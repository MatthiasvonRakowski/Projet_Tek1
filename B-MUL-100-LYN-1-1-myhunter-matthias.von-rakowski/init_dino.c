/*
** EPITECH PROJECT, 2022
** init_dino
** File description:
** init dino
*/

#include "include/my.h"

void init_dino_recsp(sfIntRect *recsp)
{
    recsp[0] = (sfIntRect) {216, 510, 80, 90};
    recsp[1] = (sfIntRect) {334, 510, 80, 90};
    recsp[2] = (sfIntRect) {458, 510, 80, 90};
    recsp[3] = (sfIntRect) {582, 510, 80, 90};
    recsp[4] = (sfIntRect) {725, 510, 80, 90};
    recsp[5] = (sfIntRect) {849, 510, 80, 90};
    recsp[6] = (sfIntRect) {959, 510, 80, 90};
    recsp[7] = (sfIntRect) {1081, 510, 80, 90};
}

void init_dino_death(sfIntRect *recsp)
{
    recsp[0] = (sfIntRect) {216, 400, 100, 100};
    recsp[1] = (sfIntRect) {338, 400, 100, 100};
    recsp[2] = (sfIntRect) {458, 400, 100, 100};
    recsp[3] = (sfIntRect) {606, 400, 120, 100};
    recsp[4] = (sfIntRect) {771, 400, 120, 100};
    recsp[5] = (sfIntRect) {941, 400, 120, 100};
}

void init_clock(dino_t *dino)
{
    dino->clock_mvt = sfClock_create();
    dino->clock_sp = sfClock_create();
    dino->clock_new = sfClock_create();
}

dino_t *init_dino(dino_t *dino)
{
    dino = malloc(sizeof(dino_t));
    dino->state = life;
    dino->dir = (sfVector2f) {1, 1};
    dino->pos.y = 390;
    dino->pos.x = -40;
    dino->sp = sfSprite_create();
    dino->tex = sfTexture_createFromFile("./pic/dino.png", NULL);
    dino->next = NULL;
    init_dino_recsp(dino->recsp);
    init_dino_death(dino->dead_recsp);
    dino->rec = dino->recsp[0];
    dino->indic = 0;
    dino->death_time = 0;
    dino->rand = rand() % 5 + 1;
    dino->accel = 0;
    init_clock(dino);
    return dino;
}
