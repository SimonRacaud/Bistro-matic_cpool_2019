/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Functions that display data on the screen
*/

#include "my.h"
#include "bistromatic.h"

void display_usage(char *program_name)
{
    my_putstr("USAGE\n");
    my_putstr(program_name);
    my_putstr(" base operators size_read\n\n");
    my_putstr("DESCRIPTION\n- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses and the 5 ");
    my_putstr("operators\n- size_read: number of characters to be read\n");
}

void display_result(char *res, char *base, char *op)
{
    int len_base = my_strlen(base);
    char *old_base = malloc(sizeof(char) * (len_base + 1));
    int alpha = 0;

    for (int i = 33; i < len_base + 33; i++)
        old_base[i - 33] = i;
    old_base[len_base] = '\0';
    substituate(res, old_base, base);
    substituate(res, "xyz{|}~", op);
    for (int pos = 0; pos < my_strlen(res); pos++) {
        if (res[pos] != ' ' && ((res[pos] == base[0] && alpha != 0) ||
        res[pos] != base[0])) {
                my_putchar(res[pos]);
        } else if (pos == my_strlen(res) - 1 && alpha == 0) {
            my_putchar(base[0]);
        }
        if (res[pos] != ' ' && res[pos] != op[3] && res[pos] != base[0]) {
            alpha++;
        }
    }
}
