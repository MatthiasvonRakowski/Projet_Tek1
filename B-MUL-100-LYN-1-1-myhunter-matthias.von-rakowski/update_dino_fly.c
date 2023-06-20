/*
** EPITECH PROJECT, 2022
** update_dino_fly
** File description:
** update dino fly
*/

#include "include/my.h"

void move_dino_fly(dino_fly_t *dino, gdata_t *data)
{
    if (dino->pos.x > 950 || dino->pos.x < -60)
        change_life(data, &dino->state);
    if (sfTime_asSeconds(sfClock_getElapsedTime(dino->clock_mvt)) >
        0.005) {
        if (dino->dir.x == -1)
            dino->pos.x -= dino->rand;
        else
            dino->pos.x += dino->rand;
        sfClock_restart(dino->clock_mvt);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(dino->clock_sp)) >
        0.2) {
        dino->rec.left += 57;
        if (dino->rec.left > 200) {
            dino->rec.left = 0;
        }
        sfClock_restart(dino->clock_sp);
    }
}

void death_dino_fly_falled(dino_fly_t *dino)
{
    if (dino->pos.y > 390 &&
        sfTime_asSeconds(sfClock_getElapsedTime(dino->clock_mvt)) > 0.005) {
            dino->death_time += -0.005 * dino->rand * 3;
        if ((dino->rand + dino->death_time > 0) &&
            dino->dir.x == 1) {
            dino->pos.x += dino->rand + dino->death_time;
        }
        if ((dino->rand + dino->death_time > 0) &&
            dino->dir.x == -1) {
            dino->pos.x -= dino->rand + dino->death_time;
        }
        sfClock_restart(dino->clock_mvt);
    }
}

void death_dino_fly(dino_fly_t *dino)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(dino->clock_sp));
    if (time > 0.3 && dino->pos.y < 390) {
        dino->rec.left += 57;
        if (dino->rec.left > 100)
            dino->rec.left = 0;
        sfClock_restart(dino->clock_sp);
    }
    if (dino->pos.y < 390 &&
        sfTime_asSeconds(sfClock_getElapsedTime(dino->clock_mvt)) > 0.005) {
        if(dino->dir.x == -1)
            dino->pos.x -= dino->rand;
        else
            dino->pos.x += dino->rand;
        dino->death_fly += 0.1;
        dino->pos.y += dino->death_fly;
        sfClock_restart(dino->clock_mvt);
        }
    death_dino_fly_falled(dino);
}

void dino_fly_manager(gdata_t *data, void *temp)
{
    dino_fly_t *temp_sec = data->dino_fly->next;

    if (data->dino_fly->state == life)
        move_dino_fly(data->dino_fly, data);
    else
        death_dino_fly(data->dino_fly);
    if (!temp)
        temp = temp_sec;
}

dino_fly_t *create_dino_fly(dino_fly_t *dino)
{
    dino_fly_t *new_dino;
    dino_fly_t *first_dino = dino;

    if (!dino)
        return (dino = init_dino_fly(new_dino));
    if (dino)
        while (dino->next) {
            dino = dino->next;
        }
    if (sfTime_asSeconds(sfClock_getElapsedTime(dino->clock_sp)) > 0.1 &&
        rand() % 90 == 0) {
            (dino->next = init_dino_fly(new_dino));
        if (rand() % 2 == 0) {
            dino->next->dir.x = -1;
            dino->next->scale.x = -2;
            dino->next->pos.x = 900;
        }
    }
    return first_dino;
}
