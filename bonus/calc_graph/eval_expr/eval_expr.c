/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** File that contain the main function of the project
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

void move_minus(char *expr_res)
{
    int i = 0;

    while (expr_res[i] != '\0') {
        if (expr_res[i] == C_MINUS && expr_res[i + 1] == C_IGNORE) {
            expr_res[i] = C_IGNORE;
            expr_res[i + 1] = C_MINUS;
        }
        i++;
    }
}

char *eval_expr(char const *str, int base)
{
    char *expr = my_strdup(str);
    char *expr_res;

    combine_operators(expr);
    expr_res = parenthesis_seeker(expr, base);
    move_minus(expr_res);
    free(expr);
    return (expr_res);
}
