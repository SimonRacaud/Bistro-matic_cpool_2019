/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Functions to calculate
*/

#include "my.h"
#include "infinadd.h"

void apply_carried_number_add(char *res, int *carriedNum, int *new_cn)
{
    if (*carriedNum != 0 && (*new_cn != 1 || *carriedNum > 1)) {
        if (*res + 1 <= '9') {
            *res += 1;
            (*carriedNum)--;
        } else {
            *res = '0';
        }
    }
}

void treat_digit_add(char *res, char const *d1, char const *d2, int *carriedNum)
{
    int new_carriedNb = 0;

    if (!is_pos_num(*d1) && *d2 != '\0') {
        *res = *d2;
    } else if (!is_pos_num(*d2) && *d1 != '\0') {
        *res = *d1;
    } else {
        if (*d1 + (*d2 - '0') <= '9') {
            *res = *d1 + (*d2 - '0');
        } else {
            *carriedNum += 1;
            new_carriedNb = 1;
            *res = (*d1 + (*d2 - '0')) - 10;
        }
    }
    apply_carried_number_add(res, carriedNum, &new_carriedNb);
}

void apply_carried_number_sub(char *res, int *carriedNum, int *new_cn)
{
    if (*carriedNum != 0 && (*new_cn != 1 || *carriedNum > 1)) {
        if (*res - 1 >= '0') {
            *res -= 1;
            (*carriedNum)--;
        } else {
            *res = '0';
        }
    }
}

void treat_digit_sub(char *res, char const *d1, char const *d2, int *carriedNum)
{
    int new_carriedNb = 0;

    if (!is_pos_num(*d2)) {
        *res = *d1;
    } else {
        if (*d1 - (*d2 - '0') >= '0') {
            *res = *d1 - (*d2 - '0');
        } else {
            *carriedNum += 1;
            new_carriedNb = 1;
            *res = 10 + (*d1 - (*d2 - '0'));
        }
    }
    apply_carried_number_sub(res, carriedNum, &new_carriedNb);
}

void calcul(char *res, char *str1, char *str2, int is_add)
{
    int carriedNum = 0;
    char *cur1 = &str1[my_strlen(str1) - 1];
    char *cur2 = &str2[my_strlen(str2) - 1];
    char out = '\0';
    int longestNb = longest(str1, str2);

    for (int i = 0; i < longestNb; i++) {
        if (is_add)
            treat_digit_add(&res[longestNb - i + 1], cur1, cur2, &carriedNum);
        else
            treat_digit_sub(&res[longestNb - i + 1], cur1, cur2, &carriedNum);
        cur1 < str1 ? cur1 = &out : cur1--;
        cur2 < str2 ? cur2 = &out : cur2--;
    }
    if (carriedNum != 0)
        res[1] = '1';
    else
        res[1] = '*';
    res[longestNb + 2] = '\0';
    apply_symbol(&res[0], str1, str2);
}
