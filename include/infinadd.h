/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Header of the program
*/

#ifndef INFINADD_H
#define INFINADD_H

int longest(char const *str1, char const *str2);
char *smaller_nb(char *str1, char *str2);
int is_pos_num(char c);
int my_strlen_num(char const *str);

void apply_carried_number_add(char *res, int *carriedNum, int *new_cn);
void treat_digit_add(char *res, char const *d1, char const *d2,
int *carriedNum);
void apply_carried_number_sub(char *res, int *carriedNum, int *new_cn);
void treat_digit_sub(char *res, char const *d1, char const *d2,
int *carriedNum);
void calcul(char *res, char *str1, char *str2, int is_add);

char *create_res_str(char const *str1, char const *str2);
void apply_symbol(char *res_symbol, char *str1, char *str2);
void display_res(char *res);
void infinadd(char *str1, char *str2);

#endif
