/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** display_options
*/

#include "my.h"

void draw_options(sfRenderWindow *window, menu_ele_t *ele)
{
    void *temp = ele;
    sfColor bl_a_wh;

    while (ele != NULL) {
        if (ele->button->state == OPEN) {
            bl_a_wh = sfRectangleShape_getFillColor(ele->button->area);
            sfRectangleShape_setFillColor(ele->button->area,
                black_and_white(bl_a_wh));
        } else
            sfRectangleShape_setFillColor(ele->button->area,
                (sfColor) {COLOR_BUTTON});
        sfRenderWindow_drawRectangleShape(window,
            ele->button->area, NULL);
        sfRenderWindow_drawText(window, ele->text, NULL);
        ele = ele->next;
    }
    ele = temp;
}
