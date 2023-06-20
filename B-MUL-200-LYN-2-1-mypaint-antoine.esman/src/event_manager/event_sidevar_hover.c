/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** event_sidevar_hover
*/

#include "my.h"

void event_sidebar_hover(menu_ele_t *sidebar, sfMouseMoveEvent move)
{
    if (sidebar->button->is_hover(sidebar->button, &move) == sfTrue) {
        sidebar->button->state = HOVER;
    } else {
        sidebar->button->state = NONE_BUTTON_STATE;
    }
}
