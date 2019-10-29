/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Resolve the equation
*/

#include "bistromatic.h"
#include "my.h"

void remove_space(char **str)
{
    char *tmp = *str;
    int pos = 0;

    for (int i = 0; i < my_strlen(*str); i++) {
        if((*str)[i] != ' ') {
            tmp[pos++] = (*str)[i];
        }
    }
    (*str)[pos] = '\0';
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
    remove_space(&expr);
    if (check_syntax_error(expr, new_base) == 84) {
        my_putstr_error(SYNTAX_ERROR_MSG);
        exit(84);
    }
    free(new_base);
    return eval_expr(expr, my_strlen(base));
}
