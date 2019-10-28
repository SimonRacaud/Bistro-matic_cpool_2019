/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

Test(evalexpr, add)
{
    char *res = eval_expr("3+2", 10);

    cr_assert_eq_str(" 5   ");
}

Test(evalexpr, sub)
{
    char *res = eval_expr("3-2", 10);

    cr_assert_eq_str(" 1   ");
}

Test(evalexpr, mul)
{
    char *res = eval_expr("3*2", 10);

    cr_assert_eq_str(" 6   ");
}

Test(evalexpr, div)
{
    char *res = eval_expr("3/2", 10);

    cr_assert_eq_str(" 1   ");
}

Test(evalexpr, mod)
{
    char *res = eval_expr("3%2", 10);

    cr_assert_eq_str(" 1   ");
}

Test(evalexpr, multiple_operators)
{
    char *res = eval_expr("2*3+6/2-10%3", 10);

    cr_assert_eq_str(" 8            ");
}

Test(evalexpr, multiple_operators_with_negative_numbers)
{
    char *res = eval_expr("2*3+(6-10)/2-10%3", 10);

    cr_assert_eq_str(" 3                 ");
}

Test(evalexpr, multiple_operators_with_parenthesis)
{
    char *res = eval_expr("1000/(34%(2*-5)+10)", 10);

    cr_assert_eq_str(" 71                  ");
}
