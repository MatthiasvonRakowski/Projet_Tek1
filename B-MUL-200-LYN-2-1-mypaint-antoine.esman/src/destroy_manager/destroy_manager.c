/*
** EPITECH PROJECT, 2022
** free
** File description:
** free all of the game structure
*/

#include "my.h"
#include "free.h"

static void menu_ele_destroy(menu_ele_t *ele)
{
    void *temp;

    while (ele != NULL) {
        sfRectangleShape_destroy(ele->button->area);
        while (ele->options != NULL) {
            sfRectangleShape_destroy(ele->options->button->area);
            temp = ele->options;
            sfText_destroy(ele->options->text);
            ele->options = ele->options->next;
            free(temp);
        }
        if (ele->text != NULL)
            sfText_destroy(ele->text);
        temp = ele;
        ele = ele->next;
        free(temp);
    }
}

void destroy_manager(paint_t *p)
{
    sfSprite_destroy(p->screen);
    sfTexture_destroy(p->texture);
    sfImage_destroy(p->image);
    sfView_destroy(p->view);
    menu_ele_destroy(p->menu);
    menu_ele_destroy(p->sidebar);
    sfRenderWindow_destroy(p->window);
    sfRectangleShape_destroy(p->select_box);
    sfRectangleShape_destroy(p->sketch_rect);
    sfCircleShape_destroy(p->sketch_circle);
    sfFont_destroy(p->font);
    free(p);
}
