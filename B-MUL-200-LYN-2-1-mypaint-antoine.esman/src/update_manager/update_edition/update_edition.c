/*
** EPITECH PROJECT, 2023
** src/update_manager/update_edition_bt
** File description:
** button edition
*/

#include "my.h"

void update_edition(paint_t *p)
{
    switch (p->paint_state) {
        case SELECTION:
            selection(p); break;
        case PENCIL_CIRCLE:
            pencil_circle(p); break;
        case PENCIL_RECT:
            pencil_rect(p); break;
        case ERASER_CIRCLE:
            eraser_circle(p); break;
        case ERASER_RECT:
            eraser_rect(p); break;
        case SHAPE_CIRCLE:
            shape_circle(p); break;
        case SHAPE_RECT:
            shape_rect(p); break;
    }
}
