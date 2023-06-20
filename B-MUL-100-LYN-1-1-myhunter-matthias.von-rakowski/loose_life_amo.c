/*
** EPITECH PROJECT, 2022
** loose_life_amo
** File description:
** change amo or life status
*/

#include "include/my.h"

void dead_state(gdata_t *data)
{
    sfSprite_destroy(data->backgrnd->sp);
    sfTexture_destroy(data->backgrnd->tex);
    data->backgrnd->sp = sfSprite_create();
    data->backgrnd->tex = sfTexture_createFromFile("./pic/dead.jpg", NULL);
    data->backgrnd->scale = (sfVector2f) {1.14, 1.5};
    data->backgrnd->rec = (sfIntRect) {0, 0, 800, 600};
    sfSprite_destroy(data->menu_buton->sp);
    sfTexture_destroy(data->menu_buton->tex);
    data->menu_buton->sp = sfSprite_create();
    data->menu_buton->tex =
        sfTexture_createFromFile("./pic/epic_fail.png", NULL);
    data->menu_buton->scale = (sfVector2f) {0.3, 0.3};
    data->menu_buton->pos = (sfVector2f) {525, 475};
    music_change(data->music, 3);
    data->game = dead;
}

void change_amo(gdata_t *data)
{
    if (data->amo->rec.left > 0 && data->amo->rec.top > 200)
        dead_state(data);
    if (data->amo->rec.top > 300) {
        data->amo->rec.top = 0;
        data->amo->rec.left += 842;
    } else {
        data->amo->rec.top += 227;
    }
}

void change_life(gdata_t *data, state_t *state)
{
    *state = dead;
    if (data->life->rec.top > 410)
        dead_state(data);
    data->life->rec.top += 111;
}
