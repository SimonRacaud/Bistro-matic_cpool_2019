/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Basic functions
*/

#include "my.h"
#include "infinadd.h"

int longest(char const *str1, char const *str2, int base)
{
    if (my_strlen_num(str1, base) > my_strlen_num(str2, base)) {
        return (my_strlen_num(str1, base));
    } else {
        return (my_strlen_num(str2, base));
    }
}

char *smaller_nb(char *str1, char *str2, int base)
{
    char *str1_cpy = str1;
    char *str2_cpy = str2;

    if (my_strlen_num(str1, base) > my_strlen_num(str2, base)) {
        return (str2);
    } else if (my_strlen_num(str1, base) < my_strlen_num(str2, base)) {
        return (str1);
    } else {
        if (!is_pos_num(str1[0], base))
            str1++;
        if (!is_pos_num(str2[0], base))
            str2++;
        if (my_strcmp(str1, str2) < 0)
            return (str1_cpy);
        else
            return (str2_cpy);
    }
}

int is_pos_num(char c, int base)
{
    if (c <= DIGIT_START + (base - 1) && c > DIGIT_START)
        return (1);
    return (0);
}

static int my_strlen_num(char const *str, int base)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (len == 0 && is_pos_num(str[i], base))
            len++;
        else if (len > 0 && (is_pos_num(str[i], base) || str[i] == DIGIT_START))
            len++;
    }
    return (len);
}
