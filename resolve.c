/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Resolve the equation
*/

#include "bistromatic.h"
#include "my.h"

static void remove_space(char **str)
{
    char *tmp = *str;
    int pos = 0;

    for (int i = 0; i < my_strlen(*str); i++) {
        if((*str)[i] != ' ') {
            tmp[pos++] = (*str)[i];
        }
    }
}

char *resolve(char *expr, char *operators, char *base)
{
    int len = my_strlen(base);
    char *new_base = malloc(sizeof(char) * len + 1);

    substituate(expr, operators, "xyz{|}~");
    for (char i = 33; i < len + 33; i++)
        new_base[i - 33] = i;
    new_base[len] = '\0';
    substituate(expr, base, new_base);
    free(new_base);
    remove_space(&expr);
    return eval_expr(expr, my_strlen(base));
}
