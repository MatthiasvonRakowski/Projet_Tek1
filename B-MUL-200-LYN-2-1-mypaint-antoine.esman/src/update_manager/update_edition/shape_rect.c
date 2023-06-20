/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** shape_rect
*/

#include "my.h"

void shape_rect(paint_t *p)
{
    if (p->evt.mouse_click == MOUSE_LEFT_RELEASED) {
        draw_rect(p, p->anchor_mpos, sfRectangleShape_getSize(
            p->select_box));
        sfTexture_updateFromImage(p->texture, p->image, 0, 0);
    }
    if (!p->mouse_down)
        return;
    sfRectangleShape_setPosition(p->select_box, (v2f){p->anchor_mpos.x,
        p->anchor_mpos.y});
    sfRectangleShape_setSize(p->select_box,
        (v2f){p->mpos.x - p->anchor_mpos.x, p->mpos.y - p->anchor_mpos.y});
}
