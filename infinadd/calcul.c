/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Functions to calculate
*/

#include "my.h"
#include "infinadd.h"
#include <stdio.h>

void apply_carried_number_add(char *res, int *carriedNum, int *new_cn, int base)
{
    if (*carriedNum != 0 && (*new_cn != 1 || *carriedNum > 1)) {
        if (*res + 1 <= DIGIT_START + (base - 1)) {
            *res += 1;
            (*carriedNum)--;
        } else {
            *res = DIGIT_START;
        }
    }
}

void treat_digit_add(char *res, char **ptr, int *carriedNum, int base)
{
    int new_carriedNb = 0;

    if (!is_pos_num(*ptr[0], base) && *ptr[1] != '\0') {
        *res = *ptr[1];
    } else if (!is_pos_num(*ptr[1], base) && *ptr[0] != '\0') {
        *res = *ptr[0];
    } else {
        if (*ptr[0] + (*ptr[1] - DIGIT_START) <= DIGIT_START + (base - 1)) {
            *res = *ptr[0] + (*ptr[1] - DIGIT_START);
        } else {
            *carriedNum += 1;
            new_carriedNb = 1;
            *res = (*ptr[0] + (*ptr[1] - DIGIT_START)) - base;
        }
    }
    apply_carried_number_add(res, carriedNum, &new_carriedNb, base);
}

void apply_carried_number_sub(char *res, int *carriedNum, int *new_cn)
{
    if (*carriedNum != 0 && (*new_cn != 1 || *carriedNum > 1)) {
        if (*res - 1 >= DIGIT_START) {
            *res -= 1;
            (*carriedNum)--;
        } else {
            *res = DIGIT_START;
        }
    }
}

void treat_digit_sub(char *res, char **ptr, int *carriedNum, int base)
{
    int new_carriedNb = 0;

    if (!is_pos_num(*ptr[1], base)) {
        *res = *ptr[0];
    } else {
        if (*ptr[0] - (*ptr[1] - DIGIT_START) >= DIGIT_START) {

            *res = *ptr[0] - (*ptr[1] - DIGIT_START);
        } else {
            *carriedNum += 1;
            new_carriedNb = 1;
            *res = base + (*ptr[0] - (*ptr[1] - DIGIT_START));
        }
    }
    apply_carried_number_sub(res, carriedNum, &new_carriedNb);
}

void calcul(char *res, char **str, int is_add, int base)
{
    int carriedNum = 0;
    char *cur[2] = {&str[0][my_strlen(str[0]) - 1]};
    char out = '\0';
    int longestNb = longest(str[0], str[1], base);

    cur[1] = &str[1][my_strlen(str[1]) - 1];
    for (int i = 0; i < longestNb; i++) {
        if (is_add)
            treat_digit_add(&res[longestNb - i + 1], cur, &carriedNum, base);
        else
            treat_digit_sub(&res[longestNb - i + 1], cur, &carriedNum, base);
        cur[0] <= str[0] || cur[0] == &out ? cur[0] = &out : cur[0]--;
        cur[1] <= str[1] || cur[1] == &out ? cur[1] = &out : cur[1]--;
    }
    if (carriedNum != 0)
        res[1] = DIGIT_START + 1;
    else
        res[1] = C_IGNORE;
    res[longestNb + 2] = '\0';
    apply_symbol(&res[0], str[0], str[1], base);
}
