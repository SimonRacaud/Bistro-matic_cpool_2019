/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Resolve the equation
*/

#include "bistromatic.h"

static void remove_space(char **str)
{
    char *tmp = *str;

    for (int i = 0; i < my_strlen(*str); i++) {
        if((*str)[i] != ' ') {
            tmp[pos] = (*str)[i];
            pos++;
        }
    }
}

char *resolve(char *expr, char *operators, char *base)
{
    substituate(expr, operators, "xyz{|}~");
    //substituate(expr, base, );
    //return eval_expr();
    return NULL; // TEMP
}
