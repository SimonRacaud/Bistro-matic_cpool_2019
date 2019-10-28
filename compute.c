/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Main function of the arithmetic part
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static int len_nbr_str(char *str, int base)
{
    int i = -1;
    int len = 0;

    while (str[++i] != '\0') {
        if (str[i] >= 33 && str[i] <= 33 + (base - 1))
            len++;
        else if (len != 0)
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
    while (str[i] < 33 || str[i] > 33 + (base - 1)) {
        if (str[i] == '\0') {
            my_putstr_error("Erreur: (debug) extract_nbr=>compute : no nbr\n"); // DEBUG
            exit(84); // DEBUG
        }
        i++;
    }
    for (int j = i; i < (i + len); i++) {
        nbr[j - i] = str[i];
        str[i] = ' ';
    }
    return (nbr);
}

static int determine_operator(char *operation)
{
    char operators[5] = "~}|z{";
    int idx = 0;

    while (*operation != '\0') {
        if (*operation < '0' || *operation > '9')
            operation++;
        else
            break;
    }
    for (int i = 0; i < 5; i++) {
        if (my_strstr(operation, operators[idx]) != NULL)
            break;
        idx++;
    }
    return (idx);
}

static void write_result(char *operation, char *result)
{
    int i = len_nbr_str(result);

    my_strncpy(operation, result, i);
    while (operation[i] != '\0')
        operation[i++] = '.';
    free(result);
}

char *compute(char *operation, int base)
{
    int a = extract_nbr(operation, base);
    int b = extract_nbr(operation, base);
    int idx_op = determine_operator(operation);
    int (*op[5])(int, int) = {&mod, &divi, &mul, &add, &sub};
    char *result = op[idx_op](a, b, base);

    write_result(operation, result);
    return (operation);
}
