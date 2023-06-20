/*
** EPITECH PROJECT, 2023
** 3_MyPaint
** File description:
** draw_rect
*/

#include "my.h"

void draw_rect(paint_t *p, sfVector2i pos, v2f size)
{
    int start_y = size.y < 0 ? size.y : 0;
    int end_y = size.y < 0 ? 0 : size.y;
    int start_x = size.x < 0 ? size.x : 0;
    int end_x = size.x < 0 ? 0 : size.x;

    for (int cy = start_y; cy < end_y;  cy++)
        for (int cx = start_x; cx < end_x;  cx++)
            draw_pixel(p, pos.x + cx, pos.y + cy);
}
