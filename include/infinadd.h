/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Header of the program
*/

#ifndef INFINADD_H
#define INFINADD_H

#define CNEG '{'
#define CPOS 'z'
#define MY_ERROR_MSG "error"
#define C_IGNORE ' '
#define DIGIT_START '!'

int longest(char const *str1, char const *str2, int base);
char *smaller_nb(char *str1, char *str2, int base);
int is_pos_num(char c, int base);

void apply_carried_number_add(char *res, int *carriedNum, int *new_cn,
int base);
void treat_digit_add(char *res, char **ptr, int *carriedNum, int base);
void apply_carried_number_sub(char *res, int *carriedNum, int *new_cn, int base);
void treat_digit_sub(char *res, char **ptr, int *carriedNum, int base);
void calcul(char *res, char **str, int is_add, int base);

void apply_symbol(char *res_symbol, char *str1, char *str2, int base);
char *infinadd_base(char *str1, char *str2, int base);

void move_string_ptr(char **cur, char **str);

#endif
