/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Arithmetic operations file
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *infinadd_base(char *str1, char *str2, int base);

void debug_display(char *str);

void substituate(char *str, char *old, char *new);

char *add_minus(char *nb, char *neg_nb)
{
    neg_nb = malloc(sizeof(char) * (my_strlen(nb) + 2));
    neg_nb[my_strlen(nb) + 1] = '\0';
    for (int i = my_strlen(nb); i > 0; i--)
        neg_nb[i] = nb[i - 1];
    neg_nb[0] = 123;
    return neg_nb;
}

int get_result_sign(char *a, char *b, int result_sign)
{
    int nb_neg = 0;

    printf("A0 = %c\n", a[0]);
    printf("B0 = %c\n", b[0]);
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
    printf("NB_NEG = %d\n", nb_neg);
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

char *make_mul(char *a, char *b, char *result, int base)
{
    char *a_mul_by_10_pow_x;

    for (int i = 0; i < my_strlen(b); i++) {
        a_mul_by_10_pow_x = add_zeros(a, a_mul_by_10_pow_x, my_strlen(b) - i - 1);
        //printf("@@@@@\n@@@@@\n@@@@@\n@@@@@\n\n");
        for (int l = 0; l < b[i] - 33; l++) {
            //printf("CALCUL = \n");
            //debug_display(result);
            //printf("  +  \n");
            //debug_display(a_mul_by_10_pow_x);
            //printf("  =  \n");
            result = infinadd_base(result, a_mul_by_10_pow_x, base);
            //debug_display(result);
            //printf("\n\n");
        }
        a_mul_by_10_pow_x = NULL;
    }
    free(a_mul_by_10_pow_x);
    return result;
}

char *add(char *a, char *b, int base)
{
    char *result = infinadd_base(a, b, base);

    return result;
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

char *mul(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result = "!";
    char *neg_result = NULL;
    //char *b_save = my_strdup(b);
    char *dif = sub(a, b, base);

    //b = b_save;
    debug_display(a);
    printf("A = %s\n\n", a);
    debug_display(b);
    printf("B = %s\n\n", b);
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
    printf("RS = %d\n", result_sign);
    debug_display(a);
    debug_display(b);
    printf("\n\n\n");
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}

char *divi(char *a, char *b, int base)
{
    int result_sign = 0;
    char *result;
    char *neg_result = NULL;
    int dif_lenght = my_strlen(a) - my_strlen(b);
    char *a_save;
    char *add_result;
    char *b_mul_by_10_pow_x;

    result_sign = get_result_sign(a, b, result_sign);
    b = sub(0, b, base);
    for (int i = dif_lenght; i >= 0; i--) {
        b_mul_by_10_pow_x = add_zeros(b, b_mul_by_10_pow_x, i);
        add_result = add_zeros("\"", add_result, i);
        while (a[0] != 33 && a[0] != 123) {
            a_save = my_strcpy(a_save, a);
            a = infinadd_base(a, b_mul_by_10_pow_x, base);
            if (a[0] != 33 && a[0] != 123) {
                result = infinadd_base(result, add_result, base);
            } else if (a[0] != 33) {
                result = infinadd_base(result, add_result, base);
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
    char *neg_result = NULL;

    if (a[0] == 123 && b[0] == 123)
        result_sign = -1;
    result_sign = get_result_sign(a, b, result_sign);
    result = sub(a, divi(a, b, base), base);
    if (result_sign == -1) {
        neg_result = add_minus(result, neg_result);
        return neg_result;
    }
    return result;
}
