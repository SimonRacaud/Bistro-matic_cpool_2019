/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Seek the operator
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "eval_expr.h"

int detect_sign(char *seg, int base)
{
    int sign = 0;
    int i = 0;

    while (seg[i] > F_DIG + (base - 1) || seg[i] < FIRST_DIGIT) {
        if (seg[i] == C_PLUS)
            sign = i;
        if (seg[i] == C_MINUS)
            sign = i;
        i++;
    }
    return sign;
}

static int is_operator(char *seg, int i, char **op_by_priority, int prio)
{
    if (seg[i] == op_by_priority[prio][0])
        return 1;
    if (seg[i] == op_by_priority[prio][1])
        return 2;
    if (prio == 0 && seg[i] == op_by_priority[prio][2])
        return 3;
    return 0;
}

static void increase_begin(char c_seg, int sig, int *begin, int i)
{
    if (c_seg != C_IGNORE && sig != i) {
        *begin = i + 1;
    }
}

char *operator_seeker(char *seg, int seg_lenght, int prio, int base)
{
    char *op_by_priority[] = {"~}|", "z{"};
    int begin = 1;
    int sig = detect_sign(seg, base);
    int operator = 0;
    int prio_op[2] = {prio, 0};

    for (int i = 1; i < seg_lenght - 1; i++) {
        combine_operators(seg);
        operator = is_operator(seg, i, op_by_priority, prio);
        if (operator > 0 && sig != i) {
            prio_op[1] = operator - 1;
            seg = make_the_operation(seg, prio_op, begin, base);
            i = 0;
            begin = 1;
            sig = detect_sign(seg, base);
            combine_operators(seg);
        } else if (seg[i] > F_DIG + (base - 1) || seg[i] < F_DIG)
            increase_begin(seg[i], sig, &begin, i);
        operator = 0;
    }
    if (prio < 1)
        seg = operator_seeker(seg, seg_lenght, prio + 1, base);
    return seg;
}
