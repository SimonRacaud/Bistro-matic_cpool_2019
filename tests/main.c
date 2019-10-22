/*
** EPITECH PROJECT, 2019
** TEST MAIN
** File description:
** JUST FOR QUICK TEST
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *str = "4278255360";

    char *res = convert_base(str, "0123456789", "01");
    printf("%s \n", res);
    free(res);
    return (0);
}
