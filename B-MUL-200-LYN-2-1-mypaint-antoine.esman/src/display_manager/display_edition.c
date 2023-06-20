/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** display_edition
*/

#include "my.h"

void display_edition(paint_t *p)
{
    switch (p->paint_state) {
    case SELECTION: sfRenderWindow_drawRectangleShape(p->window, p->select_box,
        NULL); break;
    case SHAPE_CIRCLE:
        if (p->mouse_down)
            sfRenderWindow_drawCircleShape(p->window, p->sketch_circle, NULL);
        break;
    case SHAPE_RECT:
        if (p->mouse_down)
            sfRenderWindow_drawRectangleShape(p->window, p->select_box, NULL);
        break;
    case PENCIL_CIRCLE: sfRenderWindow_drawCircleShape(p->window,
        p->sketch_circle, NULL); break;
    case PENCIL_RECT: sfRenderWindow_drawRectangleShape(p->window,
        p->sketch_rect, NULL); break;
    default:
        break;
    }
}
