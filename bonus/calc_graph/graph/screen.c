/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Function for the screen
*/

#include "csfml.h"

static void get_type_in_screen(values_t *val)
{
    int but = val->place_n_but[1];

    if(but > -1 && but < 3)
        val->screen[10] = 1;
    if(but > 3 && but < 7)
        val->screen[10] = 1;
    if((but > 7 && but < 11) || but == 13)
        val->screen[10] = 1;
    if (but == 3 || but == 7 || but == 11 || but == 15)
        val->screen[10] = but;
    if (but == 19 || but == 12 || but == 14)
        val->screen[10] = but;
    if (but == 18)
        val->screen[10] = 20;
}


static void clean_screen(values_t *val, char *calcul)
{
    int screen_type_save = val->screen[10];
    int int_to_char[] = {49, 49, 49, 40, 48, 48, 48, 38, 47, 47, 47, 31,
    28, 35, 27, 32, 0000, 0000, 0000, 18};
    int chara = 0;

    get_type_in_screen(val);
    if (screen_type_save != val->screen[10] && screen_type_save != 0) {
        for (int i = 0; i < val->place_n_but[0] - 1; i++) {
            chara = val->screen[i];
            calcul[val->begin[0] + i] = chara + int_to_char[chara];
        }
        val->begin[0] = val->begin[0] + val->place_n_but[0] - 1;
        val->place_n_but[0] = 1;
    }
}

void display_on_screen(values_t *val, sfTexture *text, char *calcul)
{
    char *buttons[] = {"but/1.bmp", "but/2.bmp", "but/3.bmp", "but/+.bmp",
    "but/4.bmp", "but/5.bmp", "but/6.bmp", "but/-.bmp", "but/7.bmp",
    "but/8.bmp", "but/9.bmp", "but/x.bmp", "but/(.bmp", "but/0.bmp",
    "but/).bmp", "but/div.bmp", "but/sound.bmp", "but/sup.bmp", "but/=.bmp",
    "but/%.bmp"};
    sfImage **but_img = malloc(sizeof(sfImage*) * 20);
    int num = 0;

    clean_screen(val, calcul);
    for (int i = 0; i < 20; i++)
        but_img[i] = sfImage_createFromFile(buttons[i]);
    if (val->place_n_but[0] > 0) {
        if (val->place_n_but[1] != 18)
            val->screen[val->place_n_but[0] - 1] = val->place_n_but[1];
        for (int j = 0; j < val->place_n_but[0]; j++) {
            num = val->screen[val->place_n_but[0] - j - 1];
            sfTexture_updateFromImage(text, but_img[num], 510 - j * 51, 70);
        }
    }
}
