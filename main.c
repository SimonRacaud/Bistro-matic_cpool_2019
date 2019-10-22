/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Main file of the project
*/

#include <stdlib.h>
#include <unistd.h>
//#include "bistromatic.h"
#include "my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        display_usage(av[0]);
        return (EXIT_USAGE);
    }
    // Vérification validité arguments
    check_base(av[1]);
    check_ops(av[2]);
    // Lecture de l'expression
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    // substitution des opérateurs
    // ...
    // Evaluation de l'expression
    eval_expr(av[1], av[2], expr, size);
    // Affichage du résultat
    /// display_result(result);
    free(expr);
    return (EXIT_SUCCESS);
}
