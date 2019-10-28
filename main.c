/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Main file of the project
*/

#include <stdlib.h>
#include <unistd.h>
#include "bistromatic.h"
#include "my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == NULL) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;
    char *base = av[1];
    char *operators = av[2]

    if (ac != 4) {
        display_usage(av[0]);
        return (EXIT_USAGE);
    }
    check_base(base);
    check_ops(operators);
    check_double_op_base(base, operators);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    check_only_op_base_in_expr(expr, base, op);
    // substitution des opérateurs
    /// resolve(expr, base);
    /// display_result(result, base, operators);
    free(expr);
    return (EXIT_SUCCESS);
}
