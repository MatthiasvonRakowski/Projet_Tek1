/*
** EPITECH PROJECT, 2022
** init_dino_fly
** File description:
** init dino fly
*/

#include "include/my.h"

void init_clock_fly(dino_fly_t *dino)
{
    dino->clock_mvt = sfClock_create();
    dino->clock_sp = sfClock_create();
    dino->clock_new = sfClock_create();
}

dino_fly_t *init_dino_fly(dino_fly_t *dino)
{
    dino = malloc(sizeof(dino_fly_t));
    dino->state = life;
    dino->death_fly = 1.25;
    dino->dir = (sfVector2f) {1, 1};
    dino->pos.y = rand() % 320 + 40;
    dino->pos.x = -40;
    dino->scale = (sfVector2f) {2, 2};
    dino->sp = sfSprite_create();
    dino->tex = sfTexture_createFromFile("./pic/dino_fly.png", NULL);
    dino->next = NULL;
    dino->recsp = (sfIntRect) {57, 0, 57, 49};
    dino->rec = dino->recsp;
    dino->indic = 0;
    dino->death_time = 0;
    dino->rand = rand() % 5 + 2;
    dino->accel = 0;
    init_clock_fly(dino);
    return dino;
}
