/*
** EPITECH PROJECT, 2019
** check error2
** File description:
** error handling (same as check_error)
*/

#include "my.h"
#include "bistromatic.h"

int check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        return (EXIT_OPS);
    }
    return 0;
}

int check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        return (EXIT_BASE);
    }
    if (my_strlen(b) > 86) {
        return (EXIT_BASE);
    }
    return 0;
}

int check_unmatch_parenthesis(char const *str)
{
    int op_par_count = 0;
    int cl_par_count = 0;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == 'x')
            op_par_count++;
        if (str[i] == 'y')
            cl_par_count++;
    }
    if (cl_par_count != op_par_count) {
        return (84);
    }
    return 0;
}
