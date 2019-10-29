/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>
#include "my.h"

char *mod(char *a, char *b, int base);

void substituate(char *str, char *old, char *new);

Test(mod, mod_zero_by_number)
{
    char a[] = "0";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "3";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = mod(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "0");
}

Test(mod, mod_small_numbers)
{
    char a[] = "4";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "2";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = mod(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  0");
    free(res);
}

Test(mod, mod_big_numbers)
{
    char a[] = "17465765";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "654358";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = mod(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  00452457");
    free(res);
}

Test(mod, mod_large_numbers)
{
    char a[] = "234567892345678923456789";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "123456789123456789";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = mod(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  000000116467900147813578");
    free(res);
}

Test(mod, mod_negative_numbers)
{
    char a[] = "{700";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "{11";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = mod(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "{  007");
    free(res);
}

Test(mod, mod_positive_and_negative_numbers1)
{
    char a[] = "{600";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "11";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = mod(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "{  006");
    free(res);
}

Test(mod, mod_positive_and_negative_numbers2)
{
    char a[] = "600";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "{11";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = mod(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "{  006");
    free(res);
}
