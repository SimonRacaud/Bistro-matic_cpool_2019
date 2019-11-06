/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Fullfill structures
*/

#include "csfml.h"

void apply_int_res_values(values_t *val)
{
    val->int_res[0] = 7;
    val->int_res[1] = 13;
    val->int_res[2] = 0;
    val->int_res[3] = 1;
    val->int_res[4] = 2;
    val->int_res[5] = 4;
    val->int_res[6] = 5;
    val->int_res[7] = 6;
    val->int_res[8] = 8;
    val->int_res[9] = 9;
    val->int_res[10] = 10;
}

void create_values_struct(values_t *val)
{
    val->first = 1;
    val->screen[10] = 0;
    val->begin[0] = 0;
    val->place_n_but[0] = 0;
    val->place_n_but[1] = -1;
}
