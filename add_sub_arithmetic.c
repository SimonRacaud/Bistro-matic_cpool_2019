/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Add, sub and global function for arithmetic
*/

#include "my.h"
#include "bistromatic.h"

char *add(char *a, char *b, int base)
{
    char *result = infinadd_base(a, b, base);

    return result;
}

char *add_minus(char *nb, char *neg_nb)
{
    neg_nb = malloc(sizeof(char) * (my_strlen(nb) + 2));
    neg_nb[my_strlen(nb) + 1] = '\0';
    for (int i = my_strlen(nb); i > 0; i--)
        neg_nb[i] = nb[i - 1];
    neg_nb[0] = 123;
    return neg_nb;
}

char *sub(char *a, char *b, int base)
{
    char *result;
    char *neg_b = NULL;

    if (b[0] == 123) {
        b[0] = 33;
        result = infinadd_base(a, b, base);
        b[0] = 123;
    } else {
        neg_b = add_minus(b, neg_b);
        result = infinadd_base(a, neg_b, base);
    }
    return result;
}

int get_result_sign(char *a, char *b, int result_sign)
{
    int nb_neg = 0;

    if (a[0] == 123) {
        for (int i = 0; i < my_strlen(a); i++)
            a[i] = a[i + 1];
        nb_neg++;
    }
    if (b[0] == 123) {
        for (int i = 0; i < my_strlen(b); i++)
            b[i] = b[i + 1];
        nb_neg++;
    }
    if (nb_neg == 1)
        result_sign = -1;
    return result_sign;
}

char *add_zeros(char *nb, char *result, int pow_x)
{
    result = malloc(sizeof(char) * (my_strlen(nb) + pow_x + 1));
    result[my_strlen(nb) + pow_x] = '\0';
    for (int j = 0; j < my_strlen(nb); j++) {
        result[j] = nb[j];
    }
    for (int k = 0; k < pow_x; k++) {
        result[my_strlen(nb) + k] = 33;
    }
    return result;
}
