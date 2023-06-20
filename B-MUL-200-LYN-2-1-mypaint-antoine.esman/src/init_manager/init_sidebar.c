/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** init_sidebar
*/

#include "my.h"

sfRectangleShape *create_sidebar_rect(sfRectangleShape *area, v2f pos, v2f size)
{
    sfRectangleShape_setPosition(area, pos);
    sfRectangleShape_setSize(area, size);
    sfRectangleShape_setFillColor(area, (sfColor) {COLOR_BUTTON});

    return area;
}

static void set_sidebar_area(menu_ele_t *sidebar)
{
    v2f sidebar_pos = {0, 50};
    v2f sidebar_size = {300, 700};

    sidebar->button->area = create_sidebar_rect(sidebar->button->area,
        sidebar_pos, sidebar_size);
}

void init_sidebar(paint_t *p)
{
    v2f slider_pos = {25, 175};

    p->sidebar = create_menu_ele();
    p->sidebar->button->is_hover = &is_hover_fct;
    p->sidebar->button->state = NONE_BUTTON_STATE;
    set_sidebar_area(p->sidebar);
    p->sidebar->options = create_slider(slider_pos);
}
