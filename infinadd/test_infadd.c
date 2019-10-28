/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/

#include "infinadd.h"
#include <criterion/criterion.h>

Test(infinadd_base, add_zeros)
{
    char *res = infinadd_base("0", "0", 10);

    cr_assert_str_eq(res, "0");
}

Test(infinadd_base, add_zero_and_number)
{
    char *res = infinadd_base("3", "0", 10);

    cr_assert_str_eq(res, "3");
}

Test(infinadd_base, add_small_numbers)
{
    char *res = infinadd_base("1", "1", 10);

    cr_assert_str_eq(res, "2");
}

Test(infinadd_base, add_big_numbers)
{
    char *res = infinadd_base("17465765", "654358", 10);

    cr_assert_str_eq(res, "18120123");
}

Test(infinadd_base, add_large_numbers)
{
    char *res = infinadd_base("123456789123456789", "234567892345678923456789", 10);

    cr_assert_str_eq(res, "234568015802468046913578");
}

Test(infinadd_base, add_negative_numbers)
{
    char *res = infinadd_base("-600", "-700", 10);

    cr_assert_str_eq(res, "-1300");
}

Test(infinadd_base, add_positive_and_negative_numbers1)
{
    char *res = infinadd_base("-600", "700", 10);

    cr_assert_str_eq(res, "100");
}

Test(infinadd_base, add_positive_and_negative_numbers2)
{
    char *res = infinadd_base("600", "-700", 10);

    cr_assert_str_eq(res, "-100");
}
