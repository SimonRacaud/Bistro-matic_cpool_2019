/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** General draw functions
*/

#include "csfml.h"

void put_pixel(framebuffer_t *framebuffer, unsigned int x,
unsigned int y, sfColor color)
{
    int pixel_nb = (framebuffer->width) * y * 4 + ((x + 1) * 4);

    framebuffer->pixel[pixel_nb] = color.r;
    framebuffer->pixel[pixel_nb + 1] = color.g;
    framebuffer->pixel[pixel_nb + 2] = color.b;
    framebuffer->pixel[pixel_nb + 3] = color.a;
}

void draw_rect(framebuffer_t *framebuffer, sfVector2u position,
unsigned int *size, sfColor color)
{
    unsigned int y = 0;
    unsigned int x = 0;

    for (y = position.y; y < position.y + size[1]; y++) {
        for (x = position.x; x < position.x + size[0]; x++) {
            put_pixel(framebuffer, x, y, color);
        }
        x = position.x;
    }
}
