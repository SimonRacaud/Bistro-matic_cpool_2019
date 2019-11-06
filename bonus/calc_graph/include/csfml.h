/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Header for csfml
*/

#ifndef CSFML_H
#define CSFML_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Image.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
sfRenderWindow *create_render_window(void);
void destroy(sfTexture *texture, sfClock *clock,
sfSprite *sprite, sfRenderWindow *window);
void free_all(window_t *win, values_t *val, char *calcul,
framebuffer_t *fb);

void put_pixel(framebuffer_t *framebuffer, unsigned int x,
unsigned int y, sfColor color);
void draw_rect(framebuffer_t *framebuffer, sfVector2u position,
unsigned int *size, sfColor color);

void draw_calc(framebuffer_t *fb);

int *mouse_check_pos(sfWindow *window, int *place_n_but, sfClock *clock);

void display_on_screen(values_t *val, sfTexture *texture, char *calcul);

void display(sfTexture *texture, sfSprite *sprite, sfRenderWindow *window);

void apply_int_res_values(values_t *val);
void create_values_struct(values_t *val);

#endif
