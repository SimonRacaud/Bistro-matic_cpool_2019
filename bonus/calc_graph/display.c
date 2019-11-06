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

static void remove_minus_for_zero(char *res, int base)
{
    int digit_pos = 0;
    int i = -1;

    while (res[++i] != '\0') {
        if (res[i] > 33 && res[i] <= 33 + (base - 1))
            digit_pos++;
    }
    if (digit_pos)
        return;
    i = -1;
    while (res[++i] != '\0') {
        if (res[i] == '{')
            res[i] = C_IGNORE;
    }
}

static void display_str(char *res, char *base, char *op)
{
    int alpha = 0;

    for (int pos = 0; pos < my_strlen(res); pos++) {
        if (res[pos] != ' ' && ((res[pos] == base[0] && alpha != 0) ||
        res[pos] != base[0]) && res[pos] != op[2]) {
            my_putchar(res[pos]);
        } else if (pos == my_strlen(res) - 1 && alpha == 0)
            my_putchar(base[0]);
        if (res[pos] != ' ' && res[pos] != op[3] && res[pos] != base[0] &&
        res[pos] != op[2]) {
            alpha++;
        }
    }
}

void display_result(char *res, char *base, char *op)
{
    int len_base = my_strlen(base);
    char *old_base = malloc(sizeof(char) * (len_base + 1));

    for (int i = 33; i < len_base + 33; i++)
        old_base[i - 33] = i;
    old_base[len_base] = '\0';
    remove_minus_for_zero(res, len_base);
    substituate(res, "xyz{|}~", op);
    substituate(res, old_base, base);
    display_str(res, base, op);
    free(old_base);
}
