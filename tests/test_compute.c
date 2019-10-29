/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

char *compute(char *operation, int base);

Test(compute, add_zeros)
{
    char eq[] = "! { !";
    compute(eq, 10);

    cr_assert_str_eq(eq, "!    ");
}

Test(compute, add_zero_and_number)
{
    char eq[] = "{$ z !";
    compute(eq, 10);

    cr_assert_str_eq(eq, "{ $   ");
}

Test(compute, add_small_numbers)
{
    char eq[] = "\"z\"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "#  ");
}
/*
Test(compute, add_big_numbers)
{
    char eq[] = "17465765+654358";
    compute(eq, 10);

    cr_assert_str_eq(eq, "18120123       ");
}
*/

Test(compute, add_negative_numbers)
{
    char eq[] = "{\"z{\"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "{ #  ");
}

Test(compute, add_positive_and_negative_numbers1)
{
    char eq[] = "{\" z \"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "!      ");
}

Test(compute, add_positive_and_negative_numbers2)
{
    char eq[] = "\"z{\"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "!   ");
}
