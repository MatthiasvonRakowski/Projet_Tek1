/*
** EPITECH PROJECT, 2023
** src/event_manager/pointer_on_event_button
** File description:
** Button event
*/

#include "my.h"

sfBool is_open_fct (button_t* button, sfMouseMoveEvent *evt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->area);

    if (bounds.left <= evt->x && bounds.left + bounds.width >= evt->x &&
        bounds.top <= evt->y && bounds.top + bounds.height >= evt->y)
        return sfTrue;
    return sfFalse;
}

sfBool is_hover_fct (button_t* button, sfMouseMoveEvent* evt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->area);

    if (bounds.left <= evt->x && bounds.left + bounds.width >= evt->x &&
        bounds.top <= evt->y && bounds.top + bounds.height >= evt->y)
        return sfTrue;
    return sfFalse;
}

sfBool is_released_fct (button_t* button, sfMouseButtonEvent *evt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->area);

    if (bounds.left <= evt->x && bounds.left + bounds.width >= evt->x &&
        bounds.top <= evt->y && bounds.top + bounds.height >= evt->y)
        return sfTrue;
    return sfFalse;
}

sfBool is_pressed_fct(button_t *button, sfMouseButtonEvent *evt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->area);

    if (bounds.left <= evt->x && bounds.left + bounds.width >= evt->x &&
        bounds.top <= evt->y && bounds.top + bounds.height >= evt->y) {
        return sfTrue;
    }
    return sfFalse;

}
