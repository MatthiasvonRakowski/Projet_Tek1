/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** shape_circle
*/

#include "my.h"
#include "v2f_operations.h"

void shape_circle(paint_t *p)
{
    int distance = get_distance(p->anchor_mpos, p->mpos);

    if (p->evt.mouse_click == MOUSE_LEFT_RELEASED) {
        draw_circle(p, p->anchor_mpos, distance);
        sfTexture_updateFromImage(p->texture, p->image, 0, 0);
    }
    if (!p->mouse_down)
        return;
    sfCircleShape_setRadius(p->sketch_circle, distance);
    sfCircleShape_setPosition(p->sketch_circle, v2f_add_float(v2i_to_v2f(
        p->anchor_mpos), distance));
}
