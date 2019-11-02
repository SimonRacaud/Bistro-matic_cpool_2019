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
    char *base = av[1];
    char *operators = av[2];
    int error = 0;
    char *result;

    if (call_check(base, operators, ac, av) == 1)
        return (84);
    error = check_only_op_base_in_expr(expr, base, operators);
    if (error != 0)
        return (84);
    result = resolve(expr, operators, base);
    display_result(result, base, operators);
    return (EXIT_SUCCESS);
}

Test(global, simple_calc , .init = redirect_all_stdout3)
{
    char expr[4] = "1+1";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "3"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("2");
}

Test(global, simple_calc_with_keeper, .init = redirect_all_stdout3)
{
    char expr[4] = "9+9";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "3"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("18");
}

Test(global, simple_calc_not_enough_param , .init = redirect_all_stdout3)
{
    int ret;
    char expr[4] = "1+1";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[3] = {"./", base, op};

    ret = bistro(3, av, expr);
    cr_assert(ret == 84);
}

Test(global, simple_calc_with_par , .init = redirect_all_stdout3)
{
    char expr[8] = "3*(3+3)";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "7"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("18");
}

Test(global, simple_calc_combine_op , .init = redirect_all_stdout3)
{
    char expr[8] = "----3+3";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "8"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("6");
}

Test(global, simple_calc_just_0 , .init = redirect_all_stdout3)
{
    char expr[2] = "0";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "8"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("0");
}

Test(global, simple_calc_sub_0 , .init = redirect_all_stdout3)
{
    char expr[7] = "-(1-1)";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "8"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("0");
}

Test(global, simple_calc_div_norest , .init = redirect_all_stdout3)
{
    char expr[5] = "10/2";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "8"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("5");
}

Test(global, complex_calc, .init = redirect_all_stdout3)
{
    char expr[49] = "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16))))";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "8"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("-156");
}

Test(global, complex_calc_complex_base_op, .init = redirect_all_stdout3)
{
    char expr[13] = "-(e@-(;*!@))";
    char base[11] = "~^@!;ie& ]";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("ee");
}

Test(global, simple_calc_large_number, .init = redirect_all_stdout3)
{
    char expr[49] = "1654365856552268432465135678635489946534984324+1";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("1654365856552268432465135678635489946534984325");
}

Test(global, space_in_op, .init = redirect_all_stdout3)
{
    char expr[4] = "1 1";
    char base[11] = "0123456789";
    char op[8] = "() -*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stdout_eq_str("2");
}

Test(global, large_num_spe, .init = redirect_all_stdout3)
{
    char expr[62] = "34876542*98765467890/(3476543568976545+-";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "12"};

    my_strcat(expr, "178654356890765445)+9");
    bistro(4, av, expr);
    cr_assert_stdout_eq_str("-10");
}

Test(global_error, base_error, .init = redirect_all_stdout3)
{
    char expr[49] = "1654365856552268432465135678635489946534984324+1";
    char base[11] = "0123456989";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(global_error, op_error, .init = redirect_all_stdout3)
{
    char expr[49] = "1654365856552268432465135678635489946534984324+1";
    char base[11] = "0123456789";
    char op[8] = "()/-*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(global_error, both_error, .init = redirect_all_stdout3)
{
    char expr[49] = "1654365856552268432465135678635489946534984324+1";
    char base[11] = "0124456789";
    char op[8] = "()/-*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(global_error, base_eq_op_error, .init = redirect_all_stdout3)
{
    char expr[49] = "1654365856552268432465135678635489946534984324+1";
    char base[11] = "012+456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(global_error, space_error, .init = redirect_all_stdout3)
{
    char expr[49] = "165436585655226843246513567863549946534984324+ 1";
    char base[11] = "0123456789";
    char op[8] = "()+-*/%";
    char *av[4] = {"./", base, op, "12"};

    bistro(4, av, expr);
    cr_assert_stderr_eq_str("syntax error");
}
