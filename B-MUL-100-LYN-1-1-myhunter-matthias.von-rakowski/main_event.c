/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/c_graphical_prog/main_event
** File description:
** the main files for the event managers
*/

#include "include/my.h"

void size_windows(sfEvent event, sfRenderWindow *window, gdata_t *data)
{
    if (event.type == sfEvtResized) {
            event_resized(data, event.size.width, event.size.height);
            sfRenderWindow_setView(window, data->view);
    }
}

void close_windows(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void event_dead(sfRenderWindow *window, gdata_t *data)
{
    sfVector2i vec;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        vec = (sfVector2i) sfMouse_getPositionRenderWindow(window);
        if (vec.x <= 787 && vec.x >= 529 && vec.y <= 529 && vec.y >= 493) {
            sfRenderWindow_close(window);
        }
    }
}

void event_end(sfRenderWindow *window, gdata_t *data)
{
    sfVector2i vec;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        vec = (sfVector2i) sfMouse_getPositionRenderWindow(window);
        if (vec.x <= 785 && vec.x >= 560 && vec.y <= 581 && vec.y >= 517) {
            sfRenderWindow_close(window);
        }
    }
}

void event_manager(sfRenderWindow *window, gdata_t *data)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        size_windows(event, window, data);
        close_windows(event, window);

        switch (data->game) {
            case (menu): event_menu(window, data); break;
            case (game): event_game(event, window, data); break;
            case (dead): event_dead(window, data); break;
            case (end): event_end(window, data); break;
            default: return;
        };
    }
}
