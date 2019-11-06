/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Mouse check
*/

#include "csfml.h"

static int *mouse_check_press(int *place_n_but, sfClock *clock)
{
    sfBool is_press = sfMouse_isButtonPressed(sfMouseLeft);
    sfTime time = sfClock_getElapsedTime(clock);
    float time_sec = sfTime_asSeconds(time);

    if (is_press == sfTrue && time_sec > 0.2) {
        if (place_n_but[0] < 10) {
            place_n_but[0]++;
        }
        time = sfClock_restart(clock);
    }
    return place_n_but;
}

static int *mouse_check_pos_for_one_button(sfVector2i position,
int *place_n_but, int *coo, sfClock *clock)
{
    if (position.x > coo[0] && position.x < coo[0] + 90) {
        if (position.y > coo[1] && position.y < coo[1] + 90) {
            place_n_but = mouse_check_press(place_n_but, clock);
        }
    }
    return place_n_but;
}

int *mouse_check_pos(sfWindow *window, int *place_n_but, sfClock *clock)
{
    sfVector2i pos = sfMouse_getPosition(window);
    int coo[] = {0, 0};
    int place_save = 0;

    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 4; j++) {
            coo[0] = 44 + j * 140;
            coo[1] = 190 + k * 120;
            place_save = place_n_but[0];
            mouse_check_pos_for_one_button(pos, place_n_but, coo, clock);
            if (place_save < place_n_but[0])
                place_n_but[1] = k * 4 + j;
        }
    }
    return place_n_but;
}
