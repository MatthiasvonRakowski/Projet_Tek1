/*
** EPITECH PROJECT, 2022
** event_manager
** File description:
** no, real programmers use cat
*/

#include "../include/my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void event_norme(data_t *data)
{
    if (data->norme.event.type == sfEvtKeyReleased &&
        data->norme.event.key.code == sfKeyS)
        if (data->draw->entities == 0) {
            data->draw->entities++;
        } else
            data->draw->entities--;
    if (data->norme.event.type == sfEvtKeyReleased &&
        data->norme.event.key.code == sfKeyL)
        if (data->draw->hitbox == 0) {
            data->draw->hitbox++;
        } else
            data->draw->hitbox--;
        if (data->norme.event.type == sfEvtKeyReleased &&
            data->norme.event.key.code == sfKeyRight &&
            data->norme.time_speed < 16)
                data->norme.time_speed *= 2;
        if (data->norme.event.type == sfEvtKeyReleased &&
            data->norme.event.key.code == sfKeyLeft &&
            data->norme.time_speed > 1)
                data->norme.time_speed /= 2;
}

norme_t event_manager(data_t *data)
{
    int pause = 0;

    while (sfRenderWindow_pollEvent(data->norme.window, &data->norme.event)) {
        if (data->norme.event.type == sfEvtClosed || (data->norme.event.type ==
            sfEvtKeyPressed && data->norme.event.key.code == sfKeyEscape))
            sfRenderWindow_close(data->norme.window);
        event_norme(data);
        if (data->norme.event.type == sfEvtKeyReleased &&
        data->norme.event.key.code == sfKeyP)
            pause = 1;
    }
    while (pause) {
        if (data->norme.event.type == sfEvtKeyReleased &&
            data->norme.event.key.code == sfKeyP)
            pause = 0;
        sfClock_restart(data->norme.clock);
    }
    return data->norme;
}
