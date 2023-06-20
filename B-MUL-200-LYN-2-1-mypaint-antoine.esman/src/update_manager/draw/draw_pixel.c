/*
** EPITECH PROJECT, 2023
** 3_MyPaint
** File description:
** draw_pixel
*/

#include "my.h"

void draw_pixel(paint_t *p, int x, int y)
{
    if (!sfIntRect_contains(&p->window_rect, x, y))
        return;
    sfImage_setPixel(p->image, x, y, p->pencil_color);
}
