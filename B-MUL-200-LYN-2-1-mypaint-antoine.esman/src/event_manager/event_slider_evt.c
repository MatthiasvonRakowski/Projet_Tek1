/*
** EPITECH PROJECT, 2023
** src/event_manager/event_slider_evt
** File description:
** slider event
*/

#include "my.h"


void event_moving_fct(menu_ele_t *ele, sfMouseButtonEvent button)
{
    if (ele->options->button->is_pressed(ele->options->button, &button))
            ele->options->button->state = PRESSED;
    else
        ele->options->button->state = NONE_BUTTON_STATE;
}
