/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** display_menu
*/

#include "my.h"

void display_menu(paint_t *p)
{
    void *temp = p->menu;
    sfColor bl_a_wh;

    while (p->menu != NULL) {
        if (p->menu->button->state == HOVER ||
            p->menu->button->state == HOVER_WAIT) {
            bl_a_wh = sfRectangleShape_getFillColor(p->menu->button->area);
            sfRectangleShape_setFillColor(p->menu->button->area,
                black_and_white(bl_a_wh));
            draw_options(p->window, p->menu->options);
        } else
            sfRectangleShape_setFillColor(p->menu->button->area,
                (sfColor) {COLOR_BUTTON});
        sfRenderWindow_drawRectangleShape(p->window,
            p->menu->button->area, NULL);
        sfRenderWindow_drawText(p->window, p->menu->text, NULL);
        p->menu = p->menu->next;
    }
    p->menu = temp;
}
