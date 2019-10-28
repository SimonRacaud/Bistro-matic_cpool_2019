/*
** EPITECH PROJECT, 2019
** test_error
** File description:
** test the error func
*/

#include "../include/bistromatic.h"
#include "../include/my.h"
#include <criterion/criterion.h>

Test(check_double_op, check_double_base_valid)
{
    printf("criterion est là");
    char *base = "0123456789";
    char *op = "()+-*/%";
    char *buf = malloc(sizeof(char) * 86);
    int a;

    check_double_op(base, op);
    a = read(0, buf, 86);
    cr_assert_str_eq(buf, "");
}
