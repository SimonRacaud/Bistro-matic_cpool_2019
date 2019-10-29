/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>
#include "bistromatic.h"

Test(compute, simple_sub)
{
    char eq[] = "! { !";
    compute(eq, 10);

    cr_assert_str_eq(eq, "{!   ");
}

Test(compute, simple_add)
{
    char eq[] = "{$ z !";
    compute(eq, 10);

    cr_assert_str_eq(eq, "{ $   ");
}

Test(compute, add_two_pos_nb)
{
    char eq[] = "\"z\"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "#  ");
}

Test(compute, add_two_neg_nb)
{
    char eq[] = "{\"z{\"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "{ #  ");
}

Test(compute, add_neg_and_pos_nb1)
{
    char eq[] = "{\" z \"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "{ !   ");
}

Test(compute, add_neg_and_pos_nb2)
{
    char eq[] = "\"z{\"";

    compute(eq, 10);
    cr_assert_str_eq(eq, "!   ");
}
