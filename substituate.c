/*
** EPITECH PROJECT, 2019
** substituate
** File description:
** to simplify the code, substituate the character
** by our own in the base and the ops
*/

#include "my.h"
#include "bistromatic.h"

static int do_i_sub_it(char *str, char old, char new, int i)
{
    if (str[i] == old) {
        str[i] = new;
        return 1;
    }
    return 0;
}

int substituate(char *str, char const *old, char const *new)
{
    int replaced = 0;

    if (my_strlen(old) != my_strlen(new)) {
        return (84);
    }
    for (int i = 0; i < my_strlen(str); i++) {
        replaced = 0;
        for (int y = 0; y < my_strlen(old) && replaced == 0; y++) {
            replaced += do_i_sub_it(str, old[y], new[y], i);
        }
    }
    return 0;
}
