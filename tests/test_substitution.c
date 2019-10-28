/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>

Test(substitution, replace_numbers)
{
    char *res = substituate_basechar("0+0", "01", "!\"");

    cr_assert_eq_str(res, "!+!");
}

Test(substitution, replace_operators)
{
    char *res = subst_operators("1ca1d1bf1c1e1g1", "abcedfg", "xyz{|}~");

    cr_assert_eq_str(res, "1zx1|1y}1z1{1~1");
}

Test(substitution, replace_all)
{
    char *res = substituate_basechar("AcaAdZbfTcYeZgY", "AZERTY", "!\"#$%&");
    res = subst_operators(res, "abcedfg", "xyz{|}~");

    cr_assert_eq_str(res, "!zx!|\"y}%z&{\"~&");
}
