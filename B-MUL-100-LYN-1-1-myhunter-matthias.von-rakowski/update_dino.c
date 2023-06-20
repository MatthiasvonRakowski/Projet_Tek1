/*
** EPITECH PROJECT, 2022
** update_dino
** File description:
** update dino
*/

#include "include/my.h"

void move_dino (gdata_t *data)
{
    if (data->dino->pos.x > 950 || data->dino->pos.x < -60)
        change_life(data, &data->dino->state);
    if (sfTime_asSeconds(sfClock_getElapsedTime(data->dino->clock_mvt)) >
        0.005) {
        if (data->dino->dir.x == -1)
            data->dino->pos.x -= data->dino->rand;
        else {
            data->dino->pos.x += data->dino->rand;
        }
        sfClock_restart(data->dino->clock_mvt);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(data->dino->clock_sp)) >
        0.1) {
        if (!(data->dino->indic == 7))
            data->dino->indic++;
        else
            data->dino->indic = 0;
    sfClock_restart(data->dino->clock_sp);
    }
    data->dino->rec = data->dino->recsp[data->dino->indic];
}

void death_dino (gdata_t *data)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(data->dino->clock_sp));
    if (time > 0.1 && data->dino->indic < 5) {
            data->dino->indic++;
        sfClock_restart(data->dino->clock_sp);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(data->dino->clock_mvt)) >
        0.005) {
            data->dino->death_time += -0.01* data->dino->rand;
        if ((data->dino->rand + data->dino->death_time > 0) &&
            data->dino->dir.x == 1) {
            data->dino->pos.x += data->dino->rand + data->dino->death_time;
        }
        if ((data->dino->rand + data->dino->death_time > 0) &&
            data->dino->dir.x == -1) {
            data->dino->pos.x -= data->dino->rand + data->dino->death_time;
        }
        sfClock_restart(data->dino->clock_mvt);
    }
    data->dino->rec = data->dino->dead_recsp[data->dino->indic];
}

void dino_manager(gdata_t *data, void *temp)
{
    dino_t *temp_sec = data->dino->next;

    if (data->dino->state != dead)
        move_dino(data);
    else
        death_dino(data);
    if (!temp)
        temp = temp_sec;
}

dino_t *create_dino(dino_t *dino)
{
    dino_t *new_dino;
    dino_t *first_dino = dino;

    if (!dino)
        return (dino = init_dino(new_dino));
    if (dino)
        while (dino->next) {
            dino = dino->next;
        }
    if (sfTime_asSeconds(sfClock_getElapsedTime(dino->clock_sp)) > 0.1 &&
        rand() % 90 == 0) {
            (dino->next = init_dino(new_dino));
        if (rand() % 2 == 0) {
            dino->next->dir.x = -1;
            dino->next->pos.x = 900;
        }
    }
    return first_dino;
}
