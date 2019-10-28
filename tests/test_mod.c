/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

Test(mod, mod_zero_by_number)
{
    char *res = mod("0", "3", 10);

    cr_assert_eq_str(res, "0");
}

Test(mod, mod_small_numbers)
{
    char *res = mod("4", "2", 10);

    cr_assert_eq_str(res, "0");
}

Test(mod, mod_big_numbers)
{
    char *res = mod("17465765", "654358", 10);

    cr_assert_eq_str(res, "452457");
}

Test(mod, mod_large_numbers)
{
    char *res = mod("234567892345678923456789", "123456789123456789", 10);

    cr_assert_eq_str(res, "116467900147813578");
}

Test(mod, mod_negative_numbers)
{
    char *res = mod("-700", "-11", 10);

    cr_assert_eq_str(res, "-7");
}

Test(mod, mod_positive_and_negative_numbers1)
{
    char *res = mod("-600", "11", 10);

    cr_assert_eq_str(res, "-54");
}

Test(mod, mod_positive_and_negative_numbers2)
{
    char *res = mod("600", "-11", 10);

    cr_assert_eq_str(res, "-54");
}
