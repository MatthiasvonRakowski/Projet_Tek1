/*
** EPITECH PROJECT, 2022
** event_menu
** File description:
** event menu
*/

#include "include/my.h"

void event_menu(sfRenderWindow *window, gdata_t *data)
{
    sfVector2i vec;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        vec = (sfVector2i) sfMouse_getPositionRenderWindow(window);
        if (vec.x <= 560 && vec.x >= 254 && vec.y <= 560 && vec.y >= 500) {
            data->game = game;
            music_change(data->music, 1);
        }
    }
}
