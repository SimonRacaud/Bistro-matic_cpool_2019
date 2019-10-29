/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Secondary file of the compute function
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static char str_is_zero(char *nbr)
{
    int i = -1;
    char is_zero = 2;

    while (nbr[++i] != '\0') {
        if (nbr[i] > FIRST_DIGIT && nbr[i] <= FIRST_DIGIT + (base - 1)) {
            is_zero = 0;
            break;
        } else if (nbr[i] == FIRST_DIGIT)
            is_zero = 1;
    }
    return (is_zero);
}

void check_mod_divi_by_zero(char *beta, int idx_op, int base)
{
    char is_zero;

    if (idx_op != 0 && idx_op != 1)
        return;
    is_zero = str_is_zero(beta);
    if (is_zero) {
        my_putstr_error(ERROR_MSG);
        exit(84);
    }
}

void remove_minus_zero(char *alpha)
{
    if (str_is_zero(alpha) == 1) {
        alpha[0] = FIRST_DIGIT;
        alpha[1] = '\0';
    }
}
