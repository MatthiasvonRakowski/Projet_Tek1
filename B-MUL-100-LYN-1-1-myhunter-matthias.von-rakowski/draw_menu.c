/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/c_graphical_prog/draw_menu
** File description:
** all menu sprites
*/

#include "include/my.h"

void draw_menu_backgrnd(sfRenderWindow *window, menu_bckgrnd_t *backgrnd)
{
    sfSprite_setTexture(backgrnd->sp, backgrnd->tex, sfTrue);
    sfSprite_setScale(backgrnd->sp, backgrnd->scale);
    sfRenderWindow_drawSprite(window, backgrnd->sp, NULL);
}

void draw_menu_buton(sfRenderWindow *window, menu_buton_t *but)
{
    sfSprite_setTexture(but->sp, but->tex, sfTrue);
    sfSprite_setScale(but->sp, but->scale);
    sfSprite_setPosition(but->sp, but->pos);
    sfRenderWindow_drawSprite(window, but->sp, NULL);
}
