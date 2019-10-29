/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>
#include "my.h"

char *add(char *a, char *b, int base);
void substituate(char *str, char *old, char *new);

Test(add, add_zeros)
{
    char a[] = "0";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "0";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, " 0");
    free(res);
}

Test(add, add_zero_and_number)
{
    char a[] = "3";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "0";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  3");
    free(res);
}

Test(add, add_small_numbers)
{
    char a[] = "1";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "1";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  2");
    free(res);
}

Test(add, add_big_numbers)
{
    char a[] = "17465765";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "654358";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  18120123");
    free(res);
}

Test(add, add_large_numbers)
{
    char a[] = "123456789123456789";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "234567892345678923456789";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  234568015802468046913578");
    free(res);
}

Test(add, add_negative_numbers)
{
    char a[] = "{600";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "{700";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "{1300");
    free(res);
}

Test(add, add_positive_and_negative_numbers1)
{
    char a[] = "{600";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "700";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  100");
    free(res);
}

Test(add, add_positive_and_negative_numbers2)
{
    char a[] = "600";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "{700";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "{ 100");
    free(res);
}

Test(add, add_posit)
{
    char a[] = "  957355803524472466608719848960457539484354850";
    substituate(a, "0123456789", "!\"#$%&'()*");
    char b[] = "6543567865435678976548976546789";
    substituate(b, "0123456789", "!\"#$%&'()*");
    char *res = add(a, b, 10);
    substituate(res, "!\"#$%&'()*", "0123456789");

    cr_assert_str_eq(res, "  957355803524479010176585284639434088460901639");
    free(res);
}

/*
  957355803524472466608719848960457539484354850
+ 000000000000006543567865435678976548976546789
= 957355803524479010176585284639434088460901639
==9573558V3524474010176585284638934088460901639
*/
