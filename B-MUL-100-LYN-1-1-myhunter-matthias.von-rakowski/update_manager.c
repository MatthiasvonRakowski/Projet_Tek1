/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/c_graphical_prog/update_manager
** File description:
** update manager
*/

#include "include/my.h"

void update_manager_dino(gdata_t *data)
{
    void *temp;
    float sec;

    if (data->dino)
        sec = sfTime_asSeconds(sfClock_getElapsedTime(data->dino->clock_sp));
    data->time = sfClock_getElapsedTime(data->clock);
    if (data->game == game) {
        data->dino = create_dino(data->dino);
        temp = data->dino;
        if (sec > 3 && data->dino) {
            temp = data->dino->next;
            delete_dino(data->dino);
            data->dino = temp;
        }
        while (data->dino) {
            dino_manager(data, temp);
            data->dino = data->dino->next;
        }
        data->dino = temp;
    }
}

void update_manager_dino_fly(gdata_t *data)
{
    void *temp;
    float sec_fly;

    if (data->dino_fly)
        sec_fly =
        sfTime_asSeconds(sfClock_getElapsedTime(data->dino_fly->clock_sp));
    if (data->game == game) {
        data->dino_fly = create_dino_fly(data->dino_fly);
        temp = data->dino_fly;
        if (sec_fly > 3 && data->dino_fly) {
            temp = data->dino_fly->next;
            delete_dino_fly(data->dino_fly);
            data->dino_fly = temp;
        }
        while (data->dino_fly) {
            dino_fly_manager(data, temp);
            data->dino_fly = data->dino_fly->next;
        }
        data->dino_fly = temp;
    }
}

void change_backgrnd(gdata_t *data)
{
    sfSprite_destroy(data->backgrnd->sp);
    sfTexture_destroy(data->backgrnd->tex);
    data->backgrnd->sp = sfSprite_create();
    data->backgrnd->tex = sfTexture_createFromFile("./pic/vict.jpg", NULL);
    data->backgrnd->scale = (sfVector2f) {1.42, 1.4};
    data->backgrnd->rec = (sfIntRect) {0, 0, 800, 600};
}

void update_manager(gdata_t *data)
{
    update_manager_dino(data);
    update_manager_dino_fly(data);
    if (data->point > 50) {
        data->game = end;
        music_change(data->music, 2);
        change_backgrnd(data);
    }
}
