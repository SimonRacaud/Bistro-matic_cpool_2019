/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Main function
*/

#include "csfml.h"
#include "bistromatic.h"
#include "my.h"

static int is_end_ext(values_t *val, char *calcul, char *char_res, int i)
{
    for (int j = 0; j < 11; j++)
        if (calcul[i] == char_res[j]) {
            val->screen[val->nb] = val->int_res[j];
            val->nb++;
            j = 10;
        }
    return val->nb;
}

static int is_end(values_t *val, char *calcul, int ac, char **av)
{
    int fd = 0;
    char *char_res = "-0123456789";

    apply_int_res_values(val);
    val->nb = 0;
    if (val->screen[10] == 20 && val->first == 1) {
            fd = open("calcul.txt", O_RDWR);
            write(fd, calcul, val->begin[0]);
            calcul = bistro(ac, av);
            val->first = 0;
            for (int i = 0; i < my_strlen(calcul); i++) {
                val->nb = is_end_ext(val, calcul, char_res, i);
            }
            val->place_n_but[0] = val->nb;
    }
    close(fd);
    return val->first;
}

static void create_and_draw_calc(values_t *val, window_t *win,
framebuffer_t *fb)
{
    create_values_struct(val);
    win->render_win = create_render_window();
    win->win_handle = sfRenderWindow_getSystemHandle(win->render_win);
    win->win = sfWindow_createFromHandle(win->win_handle, NULL);
    draw_calc(fb);
}

int main(int ac, char **av)
{
    window_t *win = malloc(sizeof(*win));
    values_t *val = malloc(sizeof(*val));
    sfEvent event;
    framebuffer_t *fb = framebuffer_create(600, 800);
    sfTexture *texture = sfTexture_create(600, 800);
    sfSprite *sprite = sfSprite_create();
    sfClock *clock = sfClock_create();
    char *calcul = malloc(sizeof(char) * my_getnbr(av[3]));

    create_and_draw_calc(val, win, fb);
    while (sfRenderWindow_isOpen(win->render_win)) {
        sfTexture_updateFromPixels(texture, fb->pixel, 600, 800, 0, 0);
        mouse_check_pos(win->win, val->place_n_but, clock);
        display_on_screen(val, texture, calcul);
        display(texture, sprite, win->render_win);
        val->first = is_end(val, calcul, ac, av);
        while (sfRenderWindow_pollEvent(win->render_win, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win->render_win);
    }
    destroy(texture, clock, sprite, win->render_win);
    free_all(win, val, calcul, fb);
    return 0;
}
