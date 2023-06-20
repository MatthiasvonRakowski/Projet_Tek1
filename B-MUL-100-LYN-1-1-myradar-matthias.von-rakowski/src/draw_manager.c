/*
** EPITECH PROJECT, 2022
** draw_manager
** File description:
** C-x C-c
*/

#include "../include/my.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <stdio.h>

void draw_tower(sfRenderWindow *window, tower_t *tower, draw_t *draw)
{
    void *temp = tower;

    while (tower) {
        sfSprite_setPosition(draw->sp_tower, (sfVector2f) {tower->pos.x - 25.6,
        tower->pos.y - 25.6});
        sfCircleShape_setPosition(draw->shape_circ, tower->pos);
        sfCircleShape_setRadius(draw->shape_circ, tower->radius);
        sfCircleShape_setOrigin(draw->shape_circ,
        (sfVector2f) {tower->radius, tower->radius});
        if (draw->entities == 0)
            sfRenderWindow_drawSprite(window, draw->sp_tower, NULL);
        if (draw->hitbox == 0)
            sfRenderWindow_drawCircleShape(window, draw->shape_circ, NULL);
        tower = tower->next;
    }
    tower = temp;
}

void draw_bckgrnd(sfRenderWindow *window, sfSprite *bckgrnd)
{
    sfRenderWindow_drawSprite(window, bckgrnd, NULL);
}

void draw_text(sfRenderWindow *window, text_t *text)
{
    sfText_setString(text->text, text->str_timer);
    sfText_setPosition(text->text, (sfVector2f) {1700, 10});
    sfRenderWindow_drawText(window, text->text, NULL);
    sfText_setString(text->text, text->str_time_speed);
    sfText_setPosition(text->text, (sfVector2f) {1700, 50});
    sfRenderWindow_drawText(window, text->text, NULL);
}

void draw_manager(data_t *data)
{
    plane_t *prev = data->list_plane->plane;

    sfRenderWindow_clear(data->norme.window, sfBlack);
    draw_bckgrnd(data->norme.window, data->draw->sp_bckgrnd);
    draw_tower(data->norme.window, data->tower, data->draw);
    draw_plane(&data->norme, data->list_plane, data->draw, prev);
    if (data->list_plane->nb_plane == 0)
        sfRenderWindow_close(data->norme.window);
    draw_text(data->norme.window, data->text);
    sfRenderWindow_display(data->norme.window);
}
