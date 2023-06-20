/*
** EPITECH PROJECT, 2022
** draw_life
** File description:
** draw life and amo
*/

#include "include/my.h"

void draw_life(sfRenderWindow *window, gdata_t *data)
{
    sfSprite_setTexture(data->life->sp, data->life->tex, sfTrue);
    sfSprite_setTextureRect(data->life->sp, data->life->rec);
    sfSprite_setScale(data->life->sp, data->life->scale);
    sfSprite_setPosition(data->life->sp, data->life->pos);
    sfSprite_setTexture(data->amo->sp, data->amo->tex, sfTrue);
    sfSprite_setTextureRect(data->amo->sp, data->amo->rec);
    sfSprite_setScale(data->amo->sp, data->amo->scale);
    sfSprite_setPosition(data->amo->sp, data->amo->pos);
    sfRenderWindow_drawSprite(window, data->life->sp, NULL);
    sfRenderWindow_drawSprite(window, data->amo->sp, NULL);
}
