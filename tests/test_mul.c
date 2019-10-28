/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

Test(mul, mul_zeros)
{
    char *res = mul("0", "0", 10);

    cr_assert_eq_str(res, "0");
}

Test(mul, mul_zero_and_number)
{
    char *res = mul("3", "0", 10);

    cr_assert_eq_str(res, "0");
}

Test(mul, mul_small_numbers)
{
    char *res = mul("4", "2", 10);

    cr_assert_eq_str(res, "8");
}

Test(mul, mul_big_numbers)
{
    char *res = mul("17465765", "654358", 10);

    cr_assert_eq_str(res, "11428863053870");
}

Test(mul, mul_large_numbers)
{
    char *res = mul("123456789123456789", "234567892345678923456789", 10);

    cr_assert_eq_str(res, "28958998820454196706447148105472950190521");
}

Test(mul, mul_negative_numbers)
{
    char *res = mul("-600", "-700", 10);

    cr_assert_eq_str(res, "420000");
}

Test(mul, mul_positive_and_negative_numbers1)
{
    char *res = mul("-600", "700", 10);

    cr_assert_eq_str(res, "-420000");
}

Test(mul, mul_positive_and_negative_numbers2)
{
    char *res = mul("600", "-700", 10);

    cr_assert_eq_str(res, "-420000");
}
