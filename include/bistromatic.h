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

#define C_IGNORE ' '
#define FIRST_DIGIT '!'

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *eval_expr(char const *str, int base);

int check_base(char const *b);
int check_ops(char const *ops);
int check_double_op_base(char *base, char *op);
int check_only_op_base_in_expr(char *expr, char *base, char *op);
int check_unmatch_parenthesis(char const *str);

int substituate(char *str, char const *old, char const *new);

void debug_display(char *str);
void display_usage(char *program_name);
void display_result(char *result, char *base, char *operators);
void remove_space(char **str);

int check_syntax_error(char const *expr, char const *base);
char *resolve(char *expr, char *operators, char *base);

char *compute(char *operation, int base);
char *mod(char *a, char *b, int base);
char *divi(char *a, char *b, int base);
char *sub(char *a, char *b, int base);
char *add(char *a, char *b, int base);
char *mul(char *a, char *b, int base);
char *add_minus(char *nb, char *neg_nb);
int get_result_sign(char *a, char *b, int result_sign);
char *add_zeros(char *nb, char *result, int pow_x);
void free_and_null(char *str);
int is_res_null(char *a, char *b, int base);
char *infinadd_base(char *str1, char *str2, int base);

void check_mod_divi_by_zero(char *beta, int idx_op, int base);
void remove_minus_zero(char *alpha, int base);

#endif
