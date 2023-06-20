/*
** EPITECH PROJECT, 2022
** event_game
** File description:
** event gmae
*/

#include "include/my.h"

void event_dino(gdata_t *data, sfVector2i vec, int *touch)
{
    if (data->dino->dir.x == 1)
        if (vec.x >= data->dino->pos.x && vec.x <= data->dino->pos.x + 80 &&
            vec.y >= data->dino->pos.y && vec.y <= data->dino->pos.y + 90) {
            data->dino->state = dead;
            data->dino->indic = 0;
            *touch = 2;
            data->point++;
        }
    if (data->dino->dir.x == -1)
        if (vec.x <= data->dino->pos.x && vec.x >= data->dino->pos.x - 80 &&
            vec.y >= data->dino->pos.y && vec.y <= data->dino->pos.y + 90) {
            data->dino->state = dead;
            data->dino->indic = 0;
            *touch = 2;
            data->point++;
        }
}

void event_dino_fly(dino_fly_t *dino, sfVector2i vec, int *touch, gdata_t *data)
{
    if (dino->dir.x == 1)
        if (vec.x >= dino->pos.x && vec.x <= dino->pos.x + 100 &&
            vec.y >= dino->pos.y && vec.y <= dino->pos.y + 100) {
            dino->state = dead;
            dino->rec = (sfIntRect) {0, 94, 57, 49};
            *touch = 2;
            data->point++;
        }
    if (dino->dir.x == -1)
        if (vec.x <= dino->pos.x && vec.x >= dino->pos.x - 100 &&
            vec.y >= dino->pos.y && vec.y <= dino->pos.y + 100) {
            dino->state = dead;
            dino->rec = (sfIntRect) {0, 94, 57, 49};
            *touch = 2;
            data->point++;
        }
}

void event_leve1_fly(sfEvent event, sfRenderWindow *window, gdata_t *data,
int *touch)
{
    dino_fly_t *temp_fly = data->dino_fly;

    while (data->dino_fly) {
        if (event.type == sfEvtMouseButtonPressed &&
            data->dino_fly->state == life) {
            event_dino_fly(data->dino_fly,
                (sfVector2i) sfMouse_getPositionRenderWindow(window), touch,
                data);
        }
        data->dino_fly = data->dino_fly->next;
    }
    data->dino_fly = temp_fly;
}

void event_game(sfEvent event, sfRenderWindow *window, gdata_t *data)
{
    dino_t *temp = data->dino;
    int touch = 0;

    if (event.type == sfEvtMouseButtonPressed) {
        touch = 1;
        sfSound_play(data->shoot->shoot);
    }
    while (data->dino) {
        if (event.type == sfEvtMouseButtonPressed &&
            data->dino->state == life) {
            event_dino(data,
                (sfVector2i) sfMouse_getPositionRenderWindow(window), &touch);
        }
        data->dino = data->dino->next;
    }
    data->dino = temp;
    event_leve1_fly(event, window, data, &touch);
    if (touch == 1)
        change_amo(data);
}
