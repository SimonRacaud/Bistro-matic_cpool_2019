/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Eval expr header
*/

#ifndef H_EVALEXPR
#define H_EVALEXPR

#define F_DIG '!'
#define C_MINUS '{'
#define C_PLUS 'z'
#define OP_PAR 'x'
#define CL_PAR 'y'

#include "bistromatic.h"

void move_minus(char *expr_res);
void combine_operators(char *expr);
int detect_sign(char *seg, int base);

char *parenthesis_seeker(char *str, int base);
char *operator_seeker(char *seg, int seg_lenght, int prio, int base);
char *make_the_operation(char *seg, int *prio_op, int begin, int base);

#endif
