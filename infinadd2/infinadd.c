/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** The file contain the main functions of the program.
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "infinadd.h"

char *create_res_str(char const *str1, char const *str2)
{
    int lenstr1 = my_strlen(str1);
    int lenstr2 = my_strlen(str2);
    int size = lenstr1;
    char *res;

    if (lenstr2 > lenstr1)
        size = lenstr2;
    res = malloc(sizeof(char) * (size + 3));
    if (res == NULL)
        return (NULL);
    return (res);
}

void apply_symbol(char *res_symbol, char *str1, char *str2)
{
    *res_symbol = '+';
    if (str1[0] == '-' && str2[0] != '-') {
        if (smaller_nb(str1, str2) == str2)
            *res_symbol = '-';
    } else if (str2[0] == '-' && str1[0] != '-') {
        if (smaller_nb(str1, str2) == str1)
            *res_symbol = '-';
    } else {
        if (str1[0] == '-' && str2[0] == '-')
            *res_symbol = '-';
    }
}

void display_res(char *res)
{
    int first_digit = 0;

    for (int i = 0; i < my_strlen(res); i++) {
        if ((first_digit == 0 && is_pos_num(res[i])) || res[i + 1] == '\0')
            first_digit = 1;
        if (first_digit || res[i] == '-')
            my_putchar(res[i]);
    }
    my_putchar('\n');
}

void infinadd(char *str1, char *str2)
{
    char *res = create_res_str(str1, str2);

    if (res == NULL) {
        write(2, "ERROR: malloc res str\n", 22);
        return;
    }
    if ((str1[0] == '-' || str2[0] == '-') && str1[0] != str2[0]) {
        if (smaller_nb(str1, str2) == str1)
            calcul(res, str2, str1, 0);
        else
            calcul(res, str1, str2, 0);
    } else
        calcul(res, str1, str2, 1);
    display_res(res);
    free(res);
}
