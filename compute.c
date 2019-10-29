/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Function that solves calculations
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static int len_nbr_str(char *str, int base)
{
    int i = -1;
    int len = 0;
    int alpha = 0;

    while (str[++i] != '\0') {
        if ((str[i] == '{' && !alpha) || (len && !alpha && str[i] == ' ')) {
            len++;
            continue;
        }
        if (str[i] >= 33 && str[i] <= 33 + (base - 1)) {
            len++;
            alpha++;
        } else if (len != 0)
            break;
    }
    return (len);
}

static char *extract_nbr(char *str, int base)
{
    int len = len_nbr_str(str, base);
    char *nbr = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (nbr == NULL) {
        my_putstr_error(ERROR_MSG);
        exit(84);
    }
    nbr[len] = '\0';
    while (str[i] == C_IGNORE) {
        if (str[i] == '\0') {
            my_putstr_error("Erreur: (debug) extract_nbr=>compute : no nbr\n");
            exit(84);
        }
        i++;
    }
    for (int j = i; j < (i + len); j++) {
        nbr[j - i] = str[j];
        str[j] = ' ';
    }
    return (nbr);
}

static int determine_operator(char *operation, char **ptr_op)
{
    char *operators[5] = {"~", "}", "|", "z", "{"};
    int idx = 0;

    for (int i = 0; i < 5; i++) {
        *ptr_op = my_strstr(operation, operators[idx]);
        if (*ptr_op != NULL)
            break;
        idx++;
    }
    if (*ptr_op == NULL) {
        my_putstr_error("Error: determine_operator : compute.c\n");
        exit(84);
    }
    **ptr_op = ' ';
    return (idx);
}

static void write_result(char *operation, char *result, int base)
{
    int i = len_nbr_str(result, base);

    while (*result == C_IGNORE)
        result++;
    my_strncpy(operation, result, i);
    while (operation[i] != '\0')
        operation[i++] = C_IGNORE;
}

char *compute(char *operation, int base)
{
    char *alpha = extract_nbr(operation, base);
    char *ptr_op;
    int idx_op = determine_operator(operation, &ptr_op);
    char *beta = extract_nbr((ptr_op + 1), base);
    char *(*op[5])(char *, char *, int) = {&mod, &divi, &mul, &add, &sub};
    char *result;

    check_mod_divi_by_zero(beta, idx_op, base);
    remove_minus_zero(alpha, base);
    result = op[idx_op](alpha, beta, base);
    write_result(operation, result, base);
    free(result);
    free(alpha);
    free(beta);
    return (operation);
}
