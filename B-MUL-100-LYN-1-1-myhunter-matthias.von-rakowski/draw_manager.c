/*
** EPITECH PROJECT, 2022
** draw_manager
** File description:
** Draw manager
*/

#include "include/my.h"

void draw_menu(sfRenderWindow *window, gdata_t *data)
{
    draw_menu_backgrnd(window, data->menu_bckgrnd);
    draw_menu_buton(window, data->menu_buton);
}

void draw_game(sfRenderWindow *window, gdata_t *data)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    draw_backgrnd(window, data->backgrnd);
    draw_dino_fly_moove(window, data->dino_fly);
    draw_dino_moove(window, data->dino);
    draw_life(window, data);
    draw_target(window, data->target);
}

void draw_end(sfRenderWindow *window, gdata_t *data)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    draw_backgrnd(window, data->backgrnd);
}

void draw_dead(sfRenderWindow *window, gdata_t *data)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    draw_backgrnd(window, data->backgrnd);
    draw_menu_buton(window, data->menu_buton);
}

void draw_manager(sfRenderWindow *window, gdata_t *data)
{
    sfRenderWindow_clear(window, sfBlack);
    switch (data->game) {
        case (menu): draw_menu(window, data); break;
        case (game): draw_game(window, data); break;
        case (end): draw_end(window, data); break;
        case (dead): draw_dead(window, data); break;
        default: return;
    };
    sfRenderWindow_display(window);
}
