/*
** EPITECH PROJECT, 2019
** test syntax
** File description:
** test the check_syntax func
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_syntax_error1, check_valid, .init = redirect_all_stdout)
{
    char *expr = "3{4{x456y";
    char *base = "0123456789";
    int error = check_syntax_error(expr, base);

    cr_assert(error == 0);
}

Test(check_syntax_error2, check_unmatch_par_op, .init = redirect_all_stdout)
{
    char *expr = "3{4{x456";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error3, check_unmatch_par_cl, .init = redirect_all_stdout)
{
    char *expr = "3{4{456y";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error4, check_misplaced_op, .init = redirect_all_stdout)
{
    char *expr = "3{4{x456zy";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error5, check_multi_op, .init = redirect_all_stdout)
{
    char *expr = "3{4{x4z{56y";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error6, check_divide_zero, .init = redirect_all_stdout)
{
    char *expr = "3{4{x4z56y}0";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error7, check_op_at_the_end, .init = redirect_all_stdout)
{
    char *expr = "3{4{x4z56yz";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error8, check_no_op, .init = redirect_all_stdout)
{
    char *expr = "3{4x4z56y";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error9, op_at_the_beginning, .init = redirect_all_stdout)
{
    char *expr = "z3{4{x4z56y";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error10, check_op_in_par, .init = redirect_all_stdout)
{
    char *expr = "3{4{xzy";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error11, check_op_at_the_end, .init = redirect_all_stdout)
{
    char *expr = "{4{x4z56y";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}
Test(check_syntax_error11, check_empty_par, .init  =  redirect_all_stdout)
{
    char *expr = "4{xy";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error11, check_op_misplaced2, .init  =  redirect_all_stdout)
{
    char *expr = "4{x4zy";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}

Test(check_syntax_error11, check_op_misplaced3, .init  =  redirect_all_stdout)
{
    char *expr = "4{xz56y";
    char *base = "0123456789";

    check_syntax_error(expr, base);
    cr_assert_stderr_eq_str("syntax error", "");
}
