/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Main header file
*/

#ifndef H_BISTRO
#define H_BISTRO

#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *eval_expr(char const *expr, char const *base);

void check_base(char const *b);
void check_ops(char const *ops);
void check_double_op_base(char *base, char *op);

void debug_display(char *str);
void display_usage(char *program_name);
void display_result(char *result, char *base, char *operators);

#endif
