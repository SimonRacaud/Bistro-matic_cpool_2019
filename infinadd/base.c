/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Basic functions
*/

#include "my.h"
#include "infinadd.h"

int longest(char const *str1, char const *str2)
{
    if (my_strlen_num(str1) > my_strlen_num(str2)) {
        return (my_strlen_num(str1));
    } else {
        return (my_strlen_num(str2));
    }
}

char *smaller_nb(char *str1, char *str2)
{
    char *str1_cpy = str1;
    char *str2_cpy = str2;

    if (my_strlen_num(str1) > my_strlen_num(str2)) {
        return (str2);
    } else if (my_strlen_num(str1) < my_strlen_num(str2)) {
        return (str1);
    } else {
        if (!is_pos_num(str1[0]))
            str1++;
        if (!is_pos_num(str2[0]))
            str2++;
        if (my_strcmp(str1, str2) < 0)
            return (str1_cpy);
        else
            return (str2_cpy);
    }
}

int is_pos_num(char c)
{
    if (c <= '9' && c >= '1')
        return (1);
    return (0);
}

int my_strlen_num(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (len == 0 && is_pos_num(str[i]))
            len++;
        else if (len > 0 && (is_pos_num(str[i]) || str[i] == '0'))
            len++;
    }
    return (len);
}
