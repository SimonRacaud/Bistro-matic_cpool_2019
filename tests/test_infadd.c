/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/

#include  <criterion/criterion.h>
#include "bistromatic.h"

Test(infinadd_base, test1)
{
    char *res = infinadd_base("1", "0", 2);

    cr_assert_str_eq(res, "1");
}

Test(infinadd_base, test2)
{
    char *res = infinadd_base("1", "1", 2);

    cr_assert_str_eq(res, "10");
}

Test(infinadd_base, test3)
{
    char *res = infinadd_base("101", "1", 2);

    cr_assert_str_eq(res, "110");
}

Test(infinadd_base, test4)
{
    char *res = infinadd_base("111", "1", 2);

    cr_assert_str_eq(res, "1000");
}

Test(infinadd_base, testB1)
{
    char *res = infinadd_base(":", ":", 16);

    cr_assert_str_eq(res, "14");
}

Test(infinadd_base, testB2)
{
    char *res = infinadd_base("9", "9", 16);

    cr_assert_str_eq(res, "12");
}

Test(infinadd_base, testB3)
{
    char *res = infinadd_base("2", "1", 16);

    cr_assert_str_eq(res, "3");
}

Test(infinadd_base, testB4)
{
    char *res = infinadd_base("?", "?", 16);

    cr_assert_str_eq(res, "1>");
}
