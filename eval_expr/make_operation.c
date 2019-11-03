/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Make the operation
*/

#include "my.h"
#include <stdlib.h>
#include "eval_expr.h"
#include "bistromatic.h"

static void is_operator(int *nb_pt_befop)
{
    if (nb_pt_befop[2] == 1) {
        nb_pt_befop[0] = 0;
        nb_pt_befop[1] = 0;
    } else {
        nb_pt_befop[0] = 1;
        nb_pt_befop[1] = 1;
    }
}

static void deter_next_char(int *nb_ptr_befop, char *ops, int op_len, int base)
{
    if (ops[op_len] <= F_DIG + (base - 1) && ops[op_len] >= F_DIG) {
        nb_ptr_befop[0] = 1;
        nb_ptr_befop[1] = 0;
        nb_ptr_befop[2] = 1;
    } else if (ops[op_len] == C_IGNORE) {
        nb_ptr_befop[0] = 0;
        nb_ptr_befop[1] = 1;
    } else
        is_operator(nb_ptr_befop);
}

static int opera_len(char *ops, char operator, int base)
{
    int op_len = 0;
    int op = 0;
    int nb_point_bef_op[3] = {1, 1, 0};
    int sign = detect_sign(ops, base);

    if (sign != 0)
        op_len = sign;
    while (nb_point_bef_op[0] == 1 || nb_point_bef_op[1] == 1 || op == 0) {
        op_len++;
        if (ops[op_len] == operator) {
            op++;
            nb_point_bef_op[2] = 0;
        }
        deter_next_char(nb_point_bef_op, ops, op_len, base);
        if (op == 2)
            break;
    }
    return op_len;
}

static char *replace_operation(char *seg, char *op, int begin, int op_len)
{
    char *tmp = op;
    int pos = 0;
    int space_counter = 0;

    for (int i = 0; i < my_strlen(op); i++) {
        if (op[i] != ' ') {
            tmp[pos++] = op[i];
        } else
            space_counter++;
    }
    for (int i = 0; i < space_counter; i++)
        tmp[pos++] = C_IGNORE;
    op[pos] = '\0';
    for (int i = 0; i < op_len; i++)
        seg[begin + i] = op[i];
    return seg;
}

char *make_the_operation(char *seg, int *prio_op, int begin, int base)
{
    int op_len = 0;
    char *op_by_prio[] = {"~}|", "z{"};
    char *operation;

    op_len = opera_len(&seg[begin], op_by_prio[prio_op[0]][prio_op[1]], base);
    operation = malloc(op_len + 1);
    operation[op_len] = '\0';
    operation = my_strncpy(operation, &seg[begin], op_len);
    operation = compute(operation, base);
    seg = replace_operation(seg, operation, begin, op_len);
    free(operation);
    operation = NULL;
    return seg;
}
