/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File for the bistromatic
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(result, test_name, .init=redirect)
{

}
