/*
** EPITECH PROJECT, 2019
** check error2
** File description:
** error handling (same as check_error)
*/

#include "my.h"

void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    if (my_strlen(b) > 86) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}
