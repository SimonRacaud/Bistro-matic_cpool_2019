/*
** EPITECH PROJECT, 2019
** substituate
** File description:
** to simplify the code, substituate the character
** by our own in the base and the ops
*/

#include "include/my.h"

static void do_i_sub_it(char *str, char old, char new, int i)
{
    if (str[i] == old) {
        str[i] = new;
    }
}

void substituate(char *str, char *old, char *new)
{
    for (int i = 0; i < my_strlen(str); i++) {
        for (int y = 0; y < my_strlen(old); y++) {
            do_i_sub_it(str, old[y], new[y], i);
        }
    }
}
