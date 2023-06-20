/*
** EPITECH PROJECT, 2023
** 3_MyPaint
** File description:
** draw_circle
*/

#include "my.h"

void draw_circle(paint_t *p, sfVector2i pos, int radius)
{
    for (int cy = -radius; cy < radius;  cy++)
        for (int cx = -radius; cx < radius;  cx++)
            SQUARE(cx) + SQUARE(cy) <= SQUARE(radius) ?
            draw_pixel(p, pos.x + cx, pos.y + cy) : NULL;
}
