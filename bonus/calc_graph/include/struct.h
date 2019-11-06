/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** Struct for pixel.c
*/

#include "csfml.h"

typedef struct framebuffer
{
    sfUint8 *pixel;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

typedef struct window
{
    sfRenderWindow *render_win;
    sfWindow *win;
    sfWindowHandle win_handle;
} window_t;

typedef struct values
{
    int place_n_but[2];
    int screen[11];
    int begin[1];
    int first;
    int int_res[11];
    int nb;
} values_t;
