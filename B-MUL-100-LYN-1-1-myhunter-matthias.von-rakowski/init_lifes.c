/*
** EPITECH PROJECT, 2022
** init_lifes
** File description:
** init amo and life
*/

#include "include/my.h"



menu_buton_t *init_life(menu_buton_t *life)
{
    life = malloc(sizeof(menu_buton_t));
    life->sp = sfSprite_create();
    life->tex = sfTexture_createFromFile("./pic/life.png", NULL);
    life->rec = (sfIntRect) {0, 0, 558, 106};
    life->scale = (sfVector2f) {0.39, 0.44};
    life->pos = (sfVector2f) {580, 560};
    return life;
}

menu_buton_t *init_amo(menu_buton_t *amo)
{
    amo = malloc(sizeof(menu_buton_t));
    amo->sp = sfSprite_create();
    amo->tex = sfTexture_createFromFile("./pic/amo.png", NULL);
    amo->rec = (sfIntRect) {0, 0, 842, 226};
    amo->scale = (sfVector2f) {0.22, 0.22};
    amo->pos = (sfVector2f) {0, 555};
    return amo;
}
