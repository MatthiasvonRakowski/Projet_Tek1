/*
** EPITECH PROJECT, 2023
** src/destroy_plane_tower_draw
** File description:
** destroy some files
*/

#include "../include/my.h"

void destroy_plane(plane_t *plane)
{
    free(plane);
}

void destroy_tower(tower_t *tower)
{
    void *temp;

    while (tower) {
        temp = tower->next;
        free(tower);
        tower = temp;
    }
}

void destroy_list_plane(list_plane_t *list)
{
    void *temp;

    while (list) {
        temp = list->next;
        free(list);
        list = temp;
    }
}

void destroy_draw(draw_t *draw)
{
    sfSprite_destroy(draw->sp_plane);
    sfSprite_destroy(draw->sp_tower);
    sfSprite_destroy(draw->sp_bckgrnd);
    sfRectangleShape_destroy(draw->shape_rect);
    sfCircleShape_destroy(draw->shape_circ);
    sfTexture_destroy(draw->tex_plane);
    sfTexture_destroy(draw->tex_bckgrnd);
    sfTexture_destroy(draw->tex_tower);
    free(draw);
}
