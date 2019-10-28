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

static char *create_res_str(char const *str1, char const *str2)
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

void apply_symbol(char *res_symbol, char *str1, char *str2, int base)
{
    *res_symbol = C_IGNORE;
    if (str1[0] == CNEG && str2[0] != CNEG) {
        if (smaller_nb(str1, str2, base) == str2)
            *res_symbol = CNEG;
    } else if (str2[0] == CNEG && str1[0] != CNEG) {
        if (smaller_nb(str1, str2, base) == str1)
            *res_symbol = CNEG;
    } else {
        if (str1[0] == CNEG && str2[0] == CNEG)
            *res_symbol = CNEG;
    }
}

char *infinadd_base(char *str1, char *str2, int base)
{
    char *res = create_res_str(str1, str2);
    char *str[2] = {str1, str2};
    char *str_rev[2] = {str2, str1};

    if (res == NULL) {
        write(2, MY_ERROR_MSG, 6);
        exit(84);
    }
    if ((str1[0] == CNEG || str2[0] == CNEG) && str1[0] != str2[0]) {
        if (smaller_nb(str1, str2, base) == str1)
            calcul(res, str_rev, 0, base);
        else
            calcul(res, str, 0, base);
    } else
        calcul(res, str, 1, base);
    return (res);
}
