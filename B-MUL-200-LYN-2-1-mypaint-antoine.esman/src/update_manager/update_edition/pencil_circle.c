/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** pencil_circle
*/

#include "my.h"

void pencil_circle(paint_t *p)
{
    sfCircleShape_setRadius(p->sketch_circle, p->pencil_size);
    if (p->sidebar->button->state == HOVER) {
        sfCircleShape_setPosition(p->sketch_circle, (v2f){310, 200});
    } else {
        sfCircleShape_setPosition(p->sketch_circle, (v2f){p->mpos.x -
            p->pencil_size, p->mpos.y - p->pencil_size });
    }
    if (!p->mouse_down || p->sidebar->button->state == HOVER)
        return;
    draw_circle(p, (sfVector2i){p->mpos.x, p->mpos.y}, p->pencil_size);
    complete_drawn(p, 1);
    sfTexture_updateFromImage(p->texture, p->image, 0, 0);
}
