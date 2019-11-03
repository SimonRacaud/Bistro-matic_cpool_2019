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

    if (a[0] == 'z')
        a[0] = C_IGNORE;
    remove_space(&a);
    for (int i = 0; i < my_strlen(b); i++) {
        a_with_zeros = add_zeros(a, a_with_zeros, my_strlen(b) - i - 1);
        for (int j = 0; j < b[i] - 33; j++) {
            result = infinadd_base(result, a_with_zeros, base);
        }
        free(a_with_zeros);
        a_with_zeros = NULL;
    }
    return result;
}

char *mul(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result = "!";
    char *neg_result = NULL;
    char *dif = sub(a, b, base);

    if (a[0] == 33 || b[0] == 33) {
        free(dif);
        return NULL;
    }
    result_sign = get_result_sign(a, b, result_sign);
    if (dif[0] == 123)
        result = make_mul(b, a, result, base);
    else
        result = make_mul(a, b, result, base);
    if (result_sign == -1)
        return add_minus(result, neg_result);
    free(dif);
    return result;
}

void free_and_null(char *str)
{
    free(str);
    str = NULL;
}

int is_res_null(char *a, char *b, int base)
{
    char *dif = NULL;

    dif = sub(a, b, base);
    if (dif[0] == 123) {
        free(dif);
        return 1;
    }
    free(dif);
    return 0;
}

int get_dif_lenght(char *a, char *b)
{
    int begin_a = 0;
    int begin_b = 0;

    while (b[begin_b] < 33 || b[begin_b] > 119) {
        begin_b++;
    }
    while (a[begin_a] < 33 || a[begin_a] > 119) {
        begin_a++;
    }
    return my_strlen(a) - my_strlen(&b[begin_b]);
}
