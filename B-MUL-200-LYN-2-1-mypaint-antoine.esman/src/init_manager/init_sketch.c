/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** init_sketch
*/

#include "my.h"

void init_sketch(paint_t *p)
{
    p->select_box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(p->select_box,
        sfColor_fromRGBA(20, 200, 150, 100));
    p->sketch_circle = sfCircleShape_create();
    sfCircleShape_setFillColor(p->sketch_circle, sfColor_fromRGBA(0, 0, 0, 0));
    sfCircleShape_setOutlineColor(p->sketch_circle, sfColor_fromRGBA(0, 0, 0,
        200));
    sfCircleShape_setOutlineThickness(p->sketch_circle, 1);
    p->sketch_rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(p->sketch_rect, sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOutlineColor(p->sketch_rect, sfColor_fromRGBA(0, 0, 0,
        200));
    sfRectangleShape_setOutlineThickness(p->sketch_rect, 1);
}
