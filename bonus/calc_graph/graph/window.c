/*
** EPITECH PROJECT, 2019
** CPool_Day13_2019
** File description:
** Create, display and destroy
*/

#include "csfml.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(*framebuffer));

    framebuffer->pixel = malloc(width * height * 32 / 8);
    framebuffer->width = width;
    framebuffer->height = height;
    return framebuffer;
}

sfRenderWindow *create_render_window(void)
{
    sfVideoMode video_mode;

    video_mode.width = 600;
    video_mode.height = 800;
    video_mode.bitsPerPixel = 32;
    return sfRenderWindow_create(video_mode, "", sfDefaultStyle, NULL);
}

void destroy(sfTexture *texture, sfClock *clock,
sfSprite *sprite, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfClock_destroy(clock);
}

void free_all(window_t *win, values_t *val, char *calcul,
framebuffer_t *fb)
{
    free(win);
    free(val);
    free(calcul);
    free(fb->pixel);
    free(fb);
}
