/*
** EPITECH PROJECT, 2023
** src/init_manager/init_event
** File description:
** init event
*/

#include "my.h"

event_t init_event(void)
{
    event_t evt;

    evt.pos = (v2i) {INIT_POS_X, INIT_POS_Y};
    evt.resize = (v2i) {INIT_RESIZE};
    evt.key = 0;
    evt.mouse_click = 0;
    evt.is_open = sfTrue;
    return evt;
}
