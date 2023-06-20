/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** create_menu_ele
*/

#include "my.h"

menu_ele_t *create_menu_ele(void)
{
    menu_ele_t *ele = malloc(sizeof(menu_ele_t));
    sfRectangleShape *area = sfRectangleShape_create();

    sfRectangleShape_setPosition(area, (v2f){0, 0});
    sfRectangleShape_setSize(area, (v2f){200, 10});
    sfRectangleShape_setFillColor(area, sfWhite);

    ele->button = malloc(sizeof(button_t));
    ele->button->area = area;
    ele->options = NULL;
    ele->text = NULL;
    ele->next = NULL;
    return ele;
}
