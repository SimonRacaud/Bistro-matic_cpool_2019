/*
** EPITECH PROJECT, 2019
** test_error
** File description:
** test the error func
*/

#include "../include/bistromatic.h"
#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout2(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_double_op, check_double_base_valid, .init = redirect_all_stdout2)
{
    char *base = "0123456789";
    char *op = "()+-*/%";
    int error = 0;

    error = check_double_op_base(base, op);
    cr_assert(error == 0);
}

Test(check_only_op_base_in_expr, check_only_op_base_valid)
{
    char *expr = "3x15+16-19";
    char *op = "()+-x/%";
    char *base = "0123456789";
    int error = 0;

    error = check_only_op_base_in_expr(expr, base, op);
    cr_assert(error == 0);
}

Test(check_only_op_base_in_expr2, check_only_op_base_error)
{
    char *expr = "3xa15+16-19";
    char *op = "()+-x/%";
    char *base = "0123456789";
    int error = 0;

    error = check_only_op_base_in_expr(expr, base, op);
    cr_assert(error == 84);
}
