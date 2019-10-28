/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** DEBUG ONLY: display human readable string.
*/

#include "my.h"

static void debug_disp_op(char op)
{
    if (op == 120)
        my_putchar('(');
    if (op == 121)
        my_putchar(')');
    if (op == 122)
        my_putchar('+');
    if (op == 123)
        my_putchar('-');
    if (op == 124)
        my_putchar('*');
    if (op == 125)
        my_putchar('/');
    if (op == 126)
        my_putchar('%');
}

void debug_display(char *str)
{
    int i = -1;

    while (str[++i] != '\0') {
        if (str[i] >= 33 && str[i] <= 42)
            my_putchar(str[i] + 15);
        if (str[i] >= 43 && str[i] <= 68)
            my_putchar(str[i] + 22);
        if (str[i] > 68 && str[i] < 120)
            my_putchar('?');
        if (str[i] >= 120 && str[i] <= 126)
            debug_disp_op(str[i]);
        if (str[i] == ' ')
            my_putchar(' ');
    }
    my_putchar('\n');
}
