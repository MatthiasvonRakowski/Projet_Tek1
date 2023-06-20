/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** update_buttons
*/

#include "my.h"
#include <math.h>

void update_action_menu(paint_t *p, menu_ele_t *options)
{
    menu_ele_t *temp = options;

    while (temp) {
        if (temp->button->state == RELEASED)
            temp->button->action(p);
        temp = temp->next;
    }
}

void update_action_sidebar(paint_t *p, menu_ele_t *slidebar)
{
    sfFloatRect slider =
        sfRectangleShape_getGlobalBounds(slidebar->button->area);

    if (p->mpos.x >= slider.left && p->mpos.x <= slider.left +
        slider.width && p->mpos.y >= slider.top && p->mpos.y <=
        slider.top + slider.height) {
        if (p->evt.pos.x != 0) {
            sfRectangleShape_setPosition(slidebar->options->button->area,
                (v2f) {p->evt.pos.x, slider.top});
            p->pencil_size = (int) ((p->evt.pos.x - slider.left) / 17 + 1);
            p->pencil_size = pow(p->pencil_size, 2);
        }
    }
}

void update_buttons(paint_t *p)
{
    menu_ele_t *temp = p->menu;

    if (p->sidebar->button->state == HOVER) {
        if (p->sidebar->options->button->state == PRESSED) {
            update_action_sidebar(p, p->sidebar->options);
        }
    }
    while (temp) {
        if (temp->button->state == HOVER || temp->button->state == HOVER_WAIT)
            update_action_menu(p, temp->options);
        temp = temp->next;
    }
}
