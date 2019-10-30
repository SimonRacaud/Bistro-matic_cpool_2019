/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Global criterion test file
*/

#include "../include/bistromatic.h"
#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>

static void redirect_all_stdout3(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static int check_nb_of_parameter(int ac , char **av)
{
    if (ac != 4) {
        display_usage(av[0]);
        return (EXIT_USAGE);
    }
    return 0;
}

static int call_check(char *base, char *operators, int ac, char **av)
{
    if (check_nb_of_parameter(ac, av) == 84)
        return 1;
    if (check_base(base) != 0)
        return 1;
    if (check_ops(operators) != 0)
        return 1;
    check_double_op_base(base, operators);
    return 0;
}

int bistro(int ac, char **av, char *expr)
{
    int size;
    //char *expr;
    char *base = av[1];
    char *operators = av[2];
    int error = 0;
    char *result;

    if (call_check(base, operators, ac, av) == 1)
        return (84);
    //size = my_getnbr(av[3]);
    //expr = get_expr(size);
    error = check_only_op_base_in_expr(expr, base, operators);
    if (error != 0)
        return (84);
    result = resolve(expr, operators, base);
    display_result(result, base, operators);
    free(expr);
    return (EXIT_SUCCESS);
}

Test(global, simple_calc, .init=redirect_all_stdout3)
{
    int ret;
    char expr[3] = "1+1";
    char *av[4] = {"", "0123456789", "()+-*/%", ""};

    ret = bistro(4, av, expr);
    cr_assert_stdout_eq_str(ret, "$");
}
