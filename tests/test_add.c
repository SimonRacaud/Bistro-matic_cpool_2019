/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

char *add(char *a, char *b, int base);

Test(add, add_zeros)
{
    char *res = add("0", "0", 10);

    cr_assert_str_eq(res, "0");
}

Test(add, add_zero_and_number)
{
    char *res = add("3", "0", 10);

    cr_assert_str_eq(res, "3");
}

Test(add, add_small_numbers)
{
    char *res = add("1", "1", 10);

    cr_assert_str_eq(res, "2");
}

Test(add, add_big_numbers)
{
    char *res = add("17465765", "654358", 10);

    cr_assert_str_eq(res, "18120123");
}

Test(add, add_large_numbers)
{
    char *res = add("123456789123456789", "234567892345678923456789", 10);

    cr_assert_str_eq(res, "234568015802468046913578");
}

Test(add, add_negative_numbers)
{
    char *res = add("-600", "-700", 10);

    cr_assert_str_eq(res, "-1300");
}

Test(add, add_positive_and_negative_numbers1)
{
    char *res = add("-600", "700", 10);

    cr_assert_str_eq(res, "100");
}

Test(add, add_positive_and_negative_numbers2)
{
    char *res = add("600", "-700", 10);

    cr_assert_str_eq(res, "-100");
}
