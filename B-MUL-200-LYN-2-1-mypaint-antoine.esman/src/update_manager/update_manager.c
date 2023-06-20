/*
** EPITECH PROJECT, 2023
** 3_MyPaint
** File description:
** pencil
*/

#include "my.h"

static void convert_event_click(paint_t *p)
{
    switch (p->evt.mouse_click) {
        case MOUSE_LEFT_PRESSED:
            p->mouse_down = sfTrue;
            p->anchor_mpos = p->mpos;
            return;
        case MOUSE_LEFT_RELEASED: p->mouse_down = sfFalse; return;
        case MOUSE_MIDDLE_PRESSED: p->mouse_middle_down = sfTrue; return;
        case MOUSE_MIDDLE_RELEASED: p->mouse_middle_down = sfFalse; return;
        default: return;
    }
}

static void convert_event(paint_t *p)
{
    if (p->evt.pos.x != INIT_POS_X && p->evt.pos.y != INIT_POS_Y) {
        p->prev_mpos = p->mpos;
        p->mpos = (v2i) {p->evt.pos.x - p->new_recali.x,
            p->evt.pos.y - p->new_recali.y};
    }
    if (p->evt.is_open == sfFalse || p->evt.key == ESCAPE)
        sfRenderWindow_close(p->window);
    if (p->evt.mouse_click)
        convert_event_click(p);
}

void update_manager(paint_t *p)
{
    convert_event(p);
    update_view(p);
    update_buttons(p);
    update_edition(p);
}
