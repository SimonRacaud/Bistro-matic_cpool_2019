/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

Test(div, div_zero_by_number)
{
    char *res = div("0", "3", 10);

    cr_assert_eq_str(res, "0");
}

Test(div, div_small_numbers)
{
    char *res = div("4", "2", 10);

    cr_assert_eq_str(res, "2");
}

Test(div, div_big_numbers)
{
    char *res = div("17465765", "654358", 10);

    cr_assert_eq_str(res, "26");
}

Test(div, div_large_numbers)
{
    char *res = div("234567892345678923456789", "123456789123456789", 10);

    cr_assert_eq_str(res, "1899999");
}

Test(div, div_negative_numbers)
{
    char *res = div("-700", "-10", 10);

    cr_assert_eq_str(res, "70");
}

Test(div, div_positive_and_negative_numbers1)
{
    char *res = div("-600", "10", 10);

    cr_assert_eq_str(res, "-60");
}

Test(div, div_positive_and_negative_numbers2)
{
    char *res = div("600", "-10", 10);

    cr_assert_eq_str(res, "-60");
}
