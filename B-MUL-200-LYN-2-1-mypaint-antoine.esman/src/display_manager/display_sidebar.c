/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** display_sidebar
*/

#include "my.h"

static void display_slider(menu_ele_t *slider, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window,
        slider->button->area, NULL);
    sfRenderWindow_drawRectangleShape(window,
        slider->options->button->area, NULL);
}

void display_sidebar(menu_ele_t *sidebar, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, sidebar->button->area,
        NULL);
    display_slider(sidebar->options, window);
}
