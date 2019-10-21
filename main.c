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

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("USAGE\n");
        my_putstr(av[0]);
        my_putstr(" base operators size_read\n\n");
        my_putstr("DESCRIPTION\n- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the parentheses and the 5 ");
        my_putstr("operators\n- size_read: number of characters to be read\n");
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
    // substitution des chiffres
    // ...
    // Détection d'erreur dans l'expression
    // ...
    // évaluation de l'expression
    my_putstr(eval_expr(av[1], av[2], expr, size));
    // Affichage du résultat
    // ...
    return (EXIT_SUCCESS);
}
