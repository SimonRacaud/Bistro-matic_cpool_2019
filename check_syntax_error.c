/*
** EPITECH PROJECT, 2019
** check syntax error
** File description:
** check syntax error, the expr needs to be substituate before
*/

#include "my.h"
#include "bistromatic.h"

static int check_if_op_has_num(char const *expr, int i)
{
    if (expr[i] >= 122 && expr[i] <= 126) {
        if (i == 0) {
            my_putstr_error(SYNTAX_ERROR_MSG);
            return (84);
        }
        if (expr[i + 1] == '\0') {
            my_putstr_error(SYNTAX_ERROR_MSG);
            return (84);
        }
        if (expr[i + 1] == 'y' || expr[i - 1] == 'x') {
            my_putstr_error(SYNTAX_ERROR_MSG);
            return (84);
        }
    }
    return 0;
}

static int check_if_next_is_op(char const *expr, int i)
{
    if ((expr[i] >= 33 && expr[i] <= 119) &&
        (expr[i + 1] == 'x')) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        return (84);
    }
    if ((expr[i] == 'y') &&
        (expr[i + 1] >= 33 && expr[i + 1] <= 119)) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        return (84);
    }
    if ((expr[i] == 'x' || expr[i] == 'y') &&
        (expr[i + 1] == 'x' || expr[i + 1] == 'y')) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        return (84);
    }
    return 0;
}

int check_syntax_error(char const *expr, char const *base)
{
    int error = 0;
    for (int i = 0; i < my_strlen(expr); i++) {
        if ((expr[i] >= 122 && expr[i] <= 126) &&
            (expr[i + 1] >= 122 && expr[i + 1] <= 126)) {
            my_putstr_error(SYNTAX_ERROR_MSG);
            error = 84;
        }
        if ((expr[i] == '~' || expr[i] == '}') && expr[i + 1] == base[0]) {
            my_putstr_error(SYNTAX_ERROR_MSG);
            error = 84;
        }
        error = check_if_next_is_op(expr, i);
        error = check_if_op_has_num(expr, i);
    }
    check_unmatch_parenthesis(expr);
    if (error == 84)
        return 84;
    return 0;
}
