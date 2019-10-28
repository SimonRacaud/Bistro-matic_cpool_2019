/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Functions that check parameters in order to find errors
*/

#include "include/my.h"
#include "include/bistromatic.h"

void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    if (my_strlen(b) > 86) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

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

void check_double_op_base(char *base, char *op)
{
    char *base_stock = base;
    char *op_stock = op;
    int error = 0;

    for (int i = 0; (i < my_strlen(base) || i < my_strlen(op)); i++) {
        for (int y = i + 1; y < my_strlen(base_stock); y++)
            error += double_base_error(base, base_stock, i, y);
        for (int y = i + 1; y < my_strlen(op_stock); y++)
            error += double_op_error(op, op_stock, i, y);
        if (error > 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
    }
}
