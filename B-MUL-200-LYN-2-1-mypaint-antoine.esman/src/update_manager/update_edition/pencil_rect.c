/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** pencil_rect
*/

#include "my.h"
#include "v2f_operations.h"

void pencil_rect(paint_t *p)
{
    v2f center_pos = (v2f){p->mpos.x - p->pencil_size / 2, p->mpos.y -
        p->pencil_size / 2 };
    sfRectangleShape_setSize(p->sketch_rect, (v2f){p->pencil_size,
        p->pencil_size});
    if (p->sidebar->button->state == HOVER) {
        sfRectangleShape_setPosition(p->sketch_rect, (v2f){310, 200});
    } else {
        sfRectangleShape_setPosition(p->sketch_rect, center_pos);
    }
    if (!p->mouse_down || p->sidebar->button->state == HOVER)
        return;
    draw_rect(p, v2f_to_v2i(center_pos), (v2f){p->pencil_size,
        p->pencil_size});
    complete_drawn(p, 0);
    sfTexture_updateFromImage(p->texture, p->image, 0, 0);
}
