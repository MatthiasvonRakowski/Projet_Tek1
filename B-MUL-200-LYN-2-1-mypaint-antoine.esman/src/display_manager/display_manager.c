/*
** EPITECH PROJECT, 2022
** draw
** File description:
** draw each element on the screen
*/

#include "my.h"

void display_manager(paint_t *p)
{
    sfRenderWindow_clear(p->window, sfColor_fromRGB(COLOR_THEME));
    sfRenderWindow_drawSprite(p->window, p->screen, NULL);
    display_edition(p);
    display_sidebar(p->sidebar, p->window);
    display_menu(p);
    sfRenderWindow_display(p->window);
}
