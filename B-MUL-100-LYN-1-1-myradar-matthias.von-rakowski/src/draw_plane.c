/*
** EPITECH PROJECT, 2023
** src/draw_plane
** File description:
** draw plane
*/

#include "../include/my.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>

void draw_sprites_plane_manager(draw_t *draw, list_plane_t *list,
norme_t *norme, int protect)
{
    sfSprite_setPosition(draw->sp_plane, (sfVector2f) {
    list->plane->rect.left, list->plane->rect.top});
    sfRectangleShape_setPosition(draw->shape_rect,
    (sfVector2f) {list->plane->rect.left, list->plane->rect.top});
    sfSprite_setRotation(draw->sp_plane, list->plane->angle);
    sfRectangleShape_setRotation(draw->shape_rect, list->plane->angle);
    if (protect)
        sfRectangleShape_setOutlineColor(draw->shape_rect, sfGreen);
    else
        sfRectangleShape_setOutlineColor(draw->shape_rect, sfRed);
    if (draw->hitbox == 0)
        sfRenderWindow_drawRectangleShape(norme->window, draw->shape_rect,
        NULL);
    if (draw->entities == 0)
        sfRenderWindow_drawSprite(norme->window, draw->sp_plane, NULL);
}

int new_nb_plane(plane_t *prev, list_plane_t * list, int nb_plane)
{
    prev->next = list->plane->next;
    destroy_plane(list->plane);
    list->plane = prev->next;
    nb_plane--;
    return nb_plane;
}

void draw_plane(norme_t *norme, list_plane_t *list, draw_t *draw, plane_t *prev)
{
    plane_t *temp = list->plane;

    while (list->plane) {
        if (norme->timer < list->plane->delay) {
            prev = list->plane;
            list->plane = list->plane->next;
            continue;
        }
        if (prev == list->plane && temp->dead == 1)
            temp = temp->next;
        if (list->plane->dead == 1) {
            list->nb_plane = new_nb_plane(prev, list, list->nb_plane);
            continue;
        }
        draw_sprites_plane_manager(draw, list, norme, list->plane->protect);
        prev = list->plane;
        list->plane = list->plane->next;
    }
    list->plane = temp;
}
