/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task18 [MODIFIED]
*/

#include <stdlib.h>

void my_putchar(char c);

static char *base_conv(int nb, int base, char const *basestr)
{
    int res[100];
    char *ret;
    int i = 0;
    int k = 0;

    while (nb != 0) {
        res[i++] = (nb % base);
        nb /= base;
    }
    ret = malloc(sizeof(char) * (i + 1));
    for (int j = (i - 1); j >= 0; j--) {
        ret[k++] = basestr[res[j]];
    }
    ret[k] = '\0';
    return (ret);
}

char *my_putnbr_base_s(int nbr, char const *base)
{
    int nb_char = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr = (-nbr);
    }
    while (base[nb_char] != '\0')
        nb_char++;
    return (base_conv(nbr, nb_char, base));
}
