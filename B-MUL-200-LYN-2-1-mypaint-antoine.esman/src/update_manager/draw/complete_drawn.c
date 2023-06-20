/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** complete_drawn
*/

#include "my.h"
#include <math.h>

void complete_drawn(paint_t *p, sfBool circle)
{
    float distance = sqrt((SQUARE((p->mpos.x - p->prev_mpos.x)) +
    SQUARE((p->mpos.y - p->prev_mpos.y))));
    float dir_x = (p->mpos.x - p->prev_mpos.x) / distance;
    float dir_y = (p->mpos.y - p->prev_mpos.y) / distance;
    int num_points = (int) distance;
    int space_between = p->pencil_size < 10 ? 1 : p->pencil_size / 10;

    for (int i = 0; i < num_points; i += space_between) {
        int x = p->prev_mpos.x + i * dir_x;
        int y = p->prev_mpos.y + i * dir_y;
        if (circle)
            draw_circle(p, (sfVector2i){x, y}, p->pencil_size);
        else
            draw_rect(p, (sfVector2i){x - p->pencil_size / 2, y -p->pencil_size
                / 2}, (v2f){p->pencil_size, p->pencil_size});
    }
}
