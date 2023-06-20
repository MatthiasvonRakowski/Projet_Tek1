/*
** EPITECH PROJECT, 2023
** src/update_manager/update_slider__bt
** File description:
** manager of update of moving sliders
*/

#include "my.h"

void moving_bt(void *ptr)
{
    paint_t *p = ptr;
    v2f slider =
        sfRectangleShape_getPosition(p->sidebar->options->button->area);

    sfRectangleShape_setPosition(p->sidebar->options->options->button->area,
        (v2f) {p->evt.pos.x, slider.y});
    ptr = p;
}
