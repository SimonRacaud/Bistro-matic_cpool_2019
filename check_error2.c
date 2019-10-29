/*
** EPITECH PROJECT, 2019
** check error2
** File description:
** error handling (same as check_error)
*/

#include "my.h"
#include "bistromatic.h"

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

void check_unmatch_parenthesis(char const *str)
{
    //str needs to be substituate before checking parenthesis
    int op_par_count = 0;
    int cl_par_count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == 'x')
            op_par_count++;
        if (str[i] == 'y')
            cl_par_count++;
    }
    if (cl_par_count != op_par_count) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(84);
    }
}
