/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** Task03 - Display the content of an array of str (the last element must be 0).
*/

#include <my.h>

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
