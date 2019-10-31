/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Div and mod
*/

#include "my.h"
#include "bistromatic.h"

int is_nb_pos(int *val, char **a_n_save)
{
    char *neg_a = sub("!", a_n_save[0], val[0]);

    if (my_strcmp(neg_a, "!") != 0) {
        if (a_n_save[0][0] != 123) {
            free(neg_a);
            return 1;
        }
    }
    free(neg_a);
    return 0;
}

void sub_while_pos(int *val, char **a_n_save, char **res_n_add, char *b_with_z)
{
    char *a_neg = sub("!", a_n_save[0], val[0]);

    while (is_nb_pos(val, a_n_save) == 1) {
        a_n_save[1] = NULL;
        a_n_save[1] = malloc(sizeof(char) * my_strlen(a_n_save[0]) + 1);
        a_n_save[1] = my_strcpy(a_n_save[1], a_n_save[0]);
        a_n_save[0] = infinadd_base(&a_n_save[1][val[1]], b_with_z, val[0]);
        if (is_nb_pos(val, a_n_save) == 1) {
            res_n_add[0] = infinadd_base(res_n_add[0], res_n_add[1], val[0]);
            val[1] = 2;
        } else if (my_strcmp(a_neg, "!") == 0) {
            res_n_add[0] = infinadd_base(res_n_add[0], res_n_add[1], val[0]);
            free(a_neg);
            break;
        } else {
            free(a_neg);
            break;
        }
        free(a_n_save[1]);
    }
}

char *make_div(char *a, int base, char *neg_b, int dif_lenght)
{
    char *b_with_zeros = "";
    int begin = 0;
    int values[] = {base, begin};
    char *a_and_save[] = {a, ""};
    char *res_and_add[] = {"!", ""};

    for (int i = dif_lenght; i >= 0; i--) {
        b_with_zeros = add_zeros(neg_b, b_with_zeros, i);
        res_and_add[1] = add_zeros("\"", res_and_add[1], i);
        sub_while_pos(values, a_and_save, res_and_add, b_with_zeros);
        a_and_save[0] = my_strcpy(a_and_save[0], a_and_save[1]);
        free_and_null(b_with_zeros);
        free_and_null(res_and_add[1]);
    }
    free(a_and_save[1]);
    return res_and_add[0];
}

char *divi(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result = "!";
    char *neg_result = NULL;
    int dif_lenght = my_strlen(a) - my_strlen(b);
    char *neg_b = NULL;

    result_sign = get_result_sign(a, b, result_sign);
    if (is_res_null(a, b, base) == 1)
        return NULL;
    neg_b = add_minus(b, neg_b);
    result = make_div(a, base, neg_b, dif_lenght);
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    free(neg_b);
    return result;
}

char *mod(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result = "!";
    char *neg_result = NULL;
    char *dif = sub(a, b, base);

    if (a[0] == 123 && b[0] == 123)
        result_sign = -1;
    result_sign = get_result_sign(a, b, result_sign);
    if (is_res_null(a, b, base) == 1 && dif[0] != 123)
        return NULL;
    if (dif[0] != 123) {
        result = sub(a, mul(divi(a, b, base), b, base), base);
    } else
        result = add(a, "!", base);
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}
