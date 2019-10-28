/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Main file of the project that contain the main function.
*/

#include <stdlib.h>
#include "my.h"

char *infinadd(char *str1, char *str2, int base);

int main(int ac, char **av)
{
    char *res;

    if (ac == 3)
        res = infinadd(av[1], av[2], 10);
    free(res);

    return (0);
}
