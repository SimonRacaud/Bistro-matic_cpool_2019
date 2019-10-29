/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Mul
*/

#include "my.h"
#include "bistromatic.h"

char *make_mul(char *a, char *b, char *result, int base)
{
    char *a_with_zeros;

    for (int i = 0; i < my_strlen(b); i++) {
        a_with_zeros = add_zeros(a, a_with_zeros, my_strlen(b) - i - 1);
        for (int l = 0; l < b[i] - 33; l++) {
            result = infinadd_base(result, a_with_zeros, base);
        }
        a_with_zeros = NULL;
    }
    free(a_with_zeros);
    return result;
}

char *mul(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result = "!";
    char *neg_result = NULL;
    char *dif = sub(a, b, base);

    if (a[0] == 33 || b[0] == 33) {
        result = malloc(sizeof(char) * 2);
        result = "0";
        return result;
    }
    result_sign = get_result_sign(a, b, result_sign);
    if (dif[0] == 123)
        result = make_mul(b, a, result, base);
    else
        result = make_mul(a, b, result, base);
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}
