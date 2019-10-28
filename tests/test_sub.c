/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

Test(sub, sub_zeros)
{
    char *res = sub("0", "0", 10);

    cr_assert_eq_str(res, "0");
}

Test(sub, sub_zero_and_number)
{
    char *res = sub("0", "3", 10);

    cr_assert_eq_str(res, "-3");
}

Test(sub, sub_small_numbers)
{
    char *res = sub("1", "1", 10);

    cr_assert_eq_str(res, "0");
}

Test(sub, sub_big_numbers)
{
    char *res = sub("17465765", "654358", 10);

    cr_assert_eq_str(res, "16811407");
}

Test(sub, sub_large_numbers)
{
    char *res = sub("123456789123456789", "234567892345678923456789", 10);

    cr_assert_eq_str(res, "-234567768888889800000000");
}

Test(sub, sub_negative_numbers)
{
    char *res = sub("-600", "-700", 10);

    cr_assert_eq_str(res, "100");
}

Test(sub, sub_positive_and_negative_numbers1)
{
    char *res = sub("-600", "700", 10);

    cr_assert_eq_str(res, "-1300");
}

Test(sub, sub_positive_and_negative_numbers2)
{
    char *res = sub("600", "-700", 10);

    cr_assert_eq_str(res, "1300");
}
