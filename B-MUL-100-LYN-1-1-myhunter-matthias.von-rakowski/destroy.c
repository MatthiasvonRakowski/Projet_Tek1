/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/c_graphical_prog/destroy
** File description:
** destroy all sprites
*/

#include "include/my.h"

void delete_dino(dino_t *dino)
{
    sfSprite_destroy(dino->sp);
    sfTexture_destroy(dino->tex);
    free(dino);
}

void delete_dino_fly(dino_fly_t *dino)
{
    sfSprite_destroy(dino->sp);
    sfTexture_destroy(dino->tex);
    free(dino);
}

void destroy_list(gdata_t *data)
{
    void *temp;

    while (data->dino) {
        temp = data->dino->next;
        delete_dino(data->dino);
        data->dino = temp;
    }
    while (data->dino_fly) {
        temp = data->dino_fly->next;
        delete_dino_fly(data->dino_fly);
        data->dino_fly = temp;
    }
}

void free_all(gdata_t *data)
{
    sfSprite_destroy(data->life->sp);
    sfTexture_destroy(data->life->tex);
    sfSprite_destroy(data->amo->sp);
    sfTexture_destroy(data->amo->tex);
    free(data->target);
    free(data->backgrnd);
    free(data->life);
    free(data->amo);
    for (int i = 0; i < 4; i++)
        sfMusic_destroy(data->music[i]);
    free(data);
}

void destroy(gdata_t *data)
{
    sfView_destroy(data->view);
    sfSound_destroy(data->shoot->shoot);
    sfSoundBuffer_destroy(data->shoot->shoot_buff);
    sfSprite_destroy(data->target->sp);
    sfSprite_destroy(data->backgrnd->sp);
    sfSprite_destroy(data->menu_bckgrnd->sp);
    sfSprite_destroy(data->menu_buton->sp);
    sfTexture_destroy(data->target->tex);
    sfTexture_destroy(data->backgrnd->tex);
    sfTexture_destroy(data->menu_bckgrnd->tex);
    sfTexture_destroy(data->menu_buton->tex);
    destroy_list(data);
    free_all(data);
}
