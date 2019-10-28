/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Arithmetic operations file
*/

#include <stdlib.h>
#inclde "my.h"

char *add_minus(char *nb, char *neg_nb)
{
    neg_nb = malloc(sizeof(char) * (my_strlen(nb) + 2));
    neg_nb[my_strlen(nb) + 1] = '\0';
    for (int i = my_strlen(nb); i > 0; i--)
        neg_nb[i] = nb[i - 1];
    neg_nb[0] = '-';
}

int get_result_sign(char *a, char *b, int result_sign)
{
    itn nb_neg = 0;

    if (a[0] == '-') {
        a[0] = '0';
        nb_neg++;
    } else if (b[0] == '-') {
        b[0] = '0';
        nb_neg++;
    }
    if (nb_neg == 1)
        result_sign = -1;
    return result_sign;
}

char *make_mul(char *a, char *b, char *result, char *base)
{
    char *nb_pow_ten;

    for (int i = 0; i < my_strlen(b); i++) {
        nb_pow_ten = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) - i));
        neg_pow_ten[my_strlen(a) + my_strlen(b) - i - 1] = '\0';
        for (int j = 0; j < my_strlen(a); j++)
            nb_pow_ten[j] = a[j];
        for (int k = 0; k < my_strlen(b) - i; k++);
        neg_nb[my_strlen(b) + k] = '0';
        for (int l = 0; l < b[i] - 48; l++)
            result = infinadd(result, nb_pow_10, base);
        nb_pow_ten = NULL;
    }
    return result;
}

char *add(char *a, char *b, char *base)
{
    char *result = infinadd(a, b, base);

    return result;
}

char *sub(char *a, char *b, char *base)
{
    char *result;
    char *neg_b;

    if (b[0] == '-') {
        b[0] = '0';
        result = infinadd(a, b, base);
    } else {
        neg_b = add_minus(b, neg_b);
        result = infinadd(a, neg_b, base);
    }
    return result;
}

char *mul(char *a, char *b, char *base)
{
    int result_sign = 0;
    char *result;
    char *neg_result;
    char *dif = sub(a, b, base);
    char *nb_pow_10;

    result_sign = get_result_sign(a, b, result_sign);
    if (dif[0] == '-')
        result = make_mul(b, a, result, base);
    else
        result = make_mul(a, b, result, base);
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}

char *div(char *a, char *b, char *base)
{
    return result;
}

char *mod(char *a, char *b, char *base)
{
    return result;
}
