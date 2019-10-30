/*
** EPITECH PROJECT, 2019
** test space
** File description:
** test the remove_spaces func
*/

#include "my.h"
#include "bistromatic.h"
#include <criterion/criterion.h>

Test(remove_space, remove_space_test)
{
    char str_with_space[] = "I have space and I like them...Wait where";
    char *str_without_space = my_strdup(str_with_space);

    remove_space(&str_without_space);
    cr_assert_str_eq(str_without_space, "IhavespaceandIlikethem...Waitwhere");
}
