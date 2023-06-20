/*
** EPITECH PROJECT, 2023
** src/update_manager/update_view
** File description:
** update resize
*/


#include "my.h"

void update_view_secondpart(paint_t *p)
{
    if (p->mouse_middle_down == sfFalse)
        p->new_recali = p->recalibrate;
    if (p->evt.resize.x != 0 || p->evt.resize.y != 0) {
        p->new_recali = (v2i) {0, 0};
        sfView_setCenter(p->view, (v2f) {p->evt.resize.x / 2,
            p->evt.resize.y / 2});
        sfView_setSize(p->view, (v2f) {p->evt.resize.x,
            p->evt.resize.y});
        sfRenderWindow_setView(p->window, p->view);
    }
}

void update_view(paint_t *p)
{
    if (p->mouse_middle_down == sfTrue && p->reca.x !=
        p->prev_mpos.x - p->mpos.x && p->reca.y !=
        p->prev_mpos.y - p->mpos.y) {
        p->reca.x = p->prev_mpos.x - p->mpos.x;
        p->reca.y = p->prev_mpos.y - p->mpos.y;
        p->recalibrate.x -= p->reca.x;
        p->recalibrate.y -= p->reca.y;
        sfView_move(p->view, (v2f) {p->reca.x, p->reca.y});
    }
    update_view_secondpart(p);
}
