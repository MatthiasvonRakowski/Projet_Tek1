/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** create_slider
*/

#include "my.h"
#include "v2f_operations.h"

static menu_ele_t *create_moving_button(v2f pos, v2f slider_size)
{
    menu_ele_t *moving_button = create_menu_ele();

    v2f size = {30, 30};
    v2f origin = {size.x / 2, size.y / 2 - slider_size.y / 2};

    sfRectangleShape_setOrigin(moving_button->button->area, origin);
    sfRectangleShape_setPosition(moving_button->button->area, pos);
    sfRectangleShape_setSize(moving_button->button->area, size);
    sfRectangleShape_setOutlineColor(moving_button->button->area, sfBlack);
    sfRectangleShape_setOutlineThickness(moving_button->button->area, 2);
    sfRectangleShape_setFillColor(moving_button->button->area, sfWhite);

    return moving_button;
}

menu_ele_t *create_slider(v2f pos)
{
    menu_ele_t *slider = create_menu_ele();

    v2f size = {200, 30};

    sfRectangleShape_setPosition(slider->button->area, pos);
    sfRectangleShape_setSize(slider->button->area, size);
    sfRectangleShape_setFillColor(slider->button->area, sfWhite);
    slider->button->is_pressed = &is_pressed_fct;

    slider->options = create_moving_button(pos, size);
    slider->options->button->is_pressed = &is_pressed_fct;


    return slider;
}
