/*
** EPITECH PROJECT, 2022
** init_menu
** File description:
** init menu
*/

#include "include/my.h"

menu_bckgrnd_t *init_menu_backgrnd(menu_bckgrnd_t *backgrnd)
{
    backgrnd = malloc(sizeof(menu_bckgrnd_t));
    backgrnd->sp = sfSprite_create();
    backgrnd->tex = sfTexture_createFromFile("./pic/menu_bck.png", NULL);
    backgrnd->scale = (sfVector2f) {1, 1};
    return backgrnd;
}

menu_buton_t *init_menu_buton(menu_buton_t *but)
{
    but = malloc(sizeof(menu_buton_t));
    but->sp = sfSprite_create();
    but->tex = sfTexture_createFromFile("./pic/menu_but.png", NULL);
    but->scale = (sfVector2f) {0.6, 0.6};
    but->pos = (sfVector2f) {250, 500};
    return but;
}
