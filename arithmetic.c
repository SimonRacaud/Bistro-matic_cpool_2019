/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Arithmetic operations file
*/

#include <stdlib.h>
#include "my.h"

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
    int nb_neg = 0;

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

char *add_zeros(char *nb, char *result, int pow_x)
{
    result = malloc(sizeof(char) * (my_strlen(nb) + pow_x));
    result[my_strlen(nb) + pow_x - 1] = '\0';
    for (int j = 0; j < my_strlen(nb); j++)
        result[j] = nb[j];
    for (int k = 0; k < pow_x; k++)
        result[my_strlen(nb) + k] = '0';
    return result;
}

char *make_mul(char *a, char *b, char *result, int base)
{
    char *a_mul_by_10_pow_x;

    for (int i = 0; i < my_strlen(b); i++) {
        a_mul_by_10_pow_x = add_zeros(a, a_mul_by_10_pow_x, my_strlen(b) - i);
        for (int l = 0; l < b[i] - 48; l++)
            result = infinadd(result, a_mul_by_10_pow_x, base);
        a_mul_by_10_pow_x = NULL;
    }
    return result;
}

char *add(char *a, char *b, int base)
{
    char *result = infinadd(a, b, base);

    return result;
}

char *sub(char *a, char *b, int base)
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

char *mul(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result;
    char *neg_result;
    char *dif = sub(a, b, base);

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

char *div(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result;
    char *neg_result;
    int dif_lenght = my_strlen(a) - my_strlen(b);
    char *a_save;
    char *add_result;

    result_sign = get_result_sign(a, b, result_sign);
    b = sub(0, b, base);
    for (int i = dif_lenght; i >= 0; i--) {
        b_mul_by_10_pow_x = add_zeros(b, b_mul_by_10_pow_x, i);
        add_result = add_zeros("1", add_result, i);
        while (a > 0) {
            a_save = my_strcpy(a_save, a);
            a = infinadd(a, b_mul_by_10_pow_x, base);
            if (a > 0) {
                result = infinadd(result, add_result, base);
            } else if (a == 0) {
                result = infinadd(result, add_result, base);
                break;
            }
        }
        a = my_strcpy(a, a_save);
        b_mul_by_10_pow_x = NULL;
        add_result = NULL;
    }
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}

char *mod(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result;
    char *neg_result;

    if (a[0] == '-' && b[0] == '-')
        result_sign = -1;
    result_sign = get_result_sign(a, b, result_sign);
    result = sub(a, div(a, b, base));
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}
