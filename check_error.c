/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Functions that check parameters in order to find errors
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

static int double_base_error(char const *b, char *base_s, int i, int y)
{
    if (b[i] == base_s[y]) {
        return 1;
    }
    return 0;
}

static int double_op_error(char const *op, char *op_s, int i, int y)
{
    if (op[i] == op_s[y]) {
        return 2;
    }
    return 0;
}

static int base_eq_op(char base, char op)
{
    if (base == op) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        return (84);
    }
    return 0;
}

int check_double_op_base(char *base, char *op)
{
    char *base_stock = base;
    char *op_stock = op;
    int error = 0;

    for (int i = 0; i < my_strlen(base); i++) {
        for (int y = 0; y < my_strlen(op); y++) {
            error += base_eq_op(base[i], op[y]);
        }
    }
    for (int i = 0; (i < my_strlen(base) || i < my_strlen(op)); i++) {
        for (int y = i + 1; y < my_strlen(base_stock); y++)
            error += double_base_error(base, base_stock, i, y);
        for (int y = i + 1; y < my_strlen(op_stock); y++)
            error += double_op_error(op, op_stock, i, y);
        if (error > 0) {
            my_putstr_error(SYNTAX_ERROR_MSG);
            return (EXIT_BASE);
        }
    }
    return 0;
}

int check_only_op_base_in_expr(char *expr, char *base, char *op)
{
    int i = -1;
    char search[2] = {0, 0};

    while (expr[++i] != '\0') {
        search[0] = expr[i];
        if (expr[i] == ' ')
            continue;
        if (my_strstr(base, search) != NULL)
            continue;
        if (my_strstr(op, search) != NULL)
            continue;
        my_putstr_error(SYNTAX_ERROR_MSG);
        return (84);
    }
    return 0;
}
