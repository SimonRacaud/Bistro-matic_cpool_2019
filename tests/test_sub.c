/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>
#include "my.h"
#include "bistromatic.h"

Test(sub, sub_zeros)
{
    char a[] = "0";
    char b[] = "0";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{0");
    free(res);
}

Test(sub, sub_zero_and_number)
{
    char a[] = "0";
    char b[] = "3";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{ 3");
    free(res);
}

Test(sub, sub_small_numbers)
{
    char a[] = "1";
    char b[] = "1";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  0");
    free(res);
}

Test(sub, sub_big_numbers)
{
    char a[] = "17465765";
    char b[] = "654358";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  16811407");
    free(res);
}

Test(sub, sub_large_numbers)
{
    char a[] = "123456789123456789";
    char b[] = "234567892345678923456789";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{ 234567768888889800000000");
    free(res);
}

Test(sub, sub_negative_numbers)
{
    char a[] = "{600";
    char b[] = "{700";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "  100");
    free(res);
}

Test(sub, sub_positive_and_negative_numbers1)
{
    char a[] = "{600";
    char b[] = "700";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, "{1300");
    free(res);
}

Test(sub, sub_positive_and_negative_numbers2)
{
    char a[] = "600";
    char b[] = "{700";
    char *res = "";

    substituate(a, "0123456789", "!\"#$%&'()*");
    substituate(b, "0123456789", "!\"#$%&'()*");
    res = sub(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");
    cr_assert_str_eq(res, " 1300");
    free(res);
}
