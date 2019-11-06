/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Draw the calc
*/

#include "csfml.h"

static void draw_button(framebuffer_t *fb, int i, int j)
{
    sfVector2u pos;
    sfColor color = sfColor_fromRGBA(0, 0, 0, 255);
    unsigned int size[] = {90, 90};

    pos.x = 44 + j * 140;
    pos.y = 190 + i * 120;
    draw_rect(fb, pos, size, color);
}

static void draw_buttons(framebuffer_t *fb)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++)
            draw_button(fb, i, j);
}

static void draw_screen(framebuffer_t *fb)
{
    sfVector2u pos;
    sfColor color = sfColor_fromRGBA(0, 0, 0, 255);
    unsigned int size[] = {520, 120};

    pos.x = 40;
    pos.y = 40;
    draw_rect(fb, pos, size, color);
}

static void draw_background(framebuffer_t *fb)
{
    sfVector2u pos;
    sfColor color = sfColor_fromRGBA(115, 115, 115, 255);
    unsigned int size[] = {580, 780};

    pos.x = 10;
    pos.y = 10;
    draw_rect(fb, pos, size, color);
}

void draw_calc(framebuffer_t *fb)
{
    draw_background(fb);
    draw_screen(fb);
    draw_buttons(fb);
}
