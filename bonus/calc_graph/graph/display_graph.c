/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** Display
*/

#include "csfml.h"

static void display_icon(sfTexture *texture, char **buttons)
{
    sfImage **but_img = malloc(sizeof(sfImage*) * 20);
    int x = 0;
    int y = 0;
    int num = 0;

    for (int i = 0; i < 20; i++)
        but_img[i] = sfImage_createFromFile(buttons[i]);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            x = 69 + j * 140;
            y = 210 + i * 120;
            sfTexture_updateFromImage(texture, but_img[num], x, y);
            num = i * 4 + j + 1;
        }
    }
}

void display(sfTexture *texture, sfSprite *sprite,
sfRenderWindow *window)
{
    char *buttons[] = {"but/1.bmp", "but/2.bmp",
    "but/3.bmp", "but/+.bmp", "but/4.bmp", "but/5.bmp",
    "but/6.bmp", "but/-.bmp", "but/7.bmp", "but/8.bmp",
    "but/9.bmp", "but/x.bmp", "but/(.bmp", "but/0.bmp",
    "but/).bmp", "but/div.bmp", "but/sound.bmp",
    "but/sup.bmp", "but/=.bmp", "but/%.bmp"};

    display_icon(texture, buttons);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}
