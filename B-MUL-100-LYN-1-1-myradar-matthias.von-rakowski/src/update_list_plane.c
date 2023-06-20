/*
** EPITECH PROJECT, 2023
** src/update_list_plane
** File description:
** update plane
*/

#include "../include/my.h"

float cal_rec(float pos, float size, int place)
{
    float temp = (pos + ((place * (size - 40)) / 2));

    return temp;
}

grid_t *creat_grid(grid_t *grid)
{
    grid_t *list = NULL;
    grid_t *element;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            element = init_grid((sfFloatRect) {cal_rec(grid->box.left,
            grid->box.width, i), cal_rec(grid->box.top, grid->box.height,
            j), cal_rec(0, grid->box.width, 1) + 40, cal_rec(0,
            grid->box.top + 40, 1)}, grid->level + 1);
            element->next = list;
            list = element;
        }
    return list;
}

void plane_moove(list_plane_t *list, tower_t *tower,
double timer, float delta_t)
{
    void *temp = list->plane;

    if (!(list->plane))
        return;
    while (list->plane) {
        if (list->plane->delay > timer) {
            list->plane = list->plane->next;
            continue;
        }
        list->plane->rect.left += list->plane->mvt_s.x * delta_t;
        list->plane->rect.top += list->plane->mvt_s.y * delta_t;
        list->plane->dist -= delta_t * list->plane->speed;
        list->plane = list->plane->next;
    }
    list->plane = temp;
}

void update_plane_manager(list_plane_t *list_plane, tower_t *tower,
norme_t norme)
{
    void *temp = list_plane->plane;

    plane_moove(list_plane, tower, norme.timer, norme.delta_t);
    while (list_plane->plane) {
        if (list_plane->plane->delay > norme.timer) {
            list_plane->plane = list_plane->plane->next;
            continue;
        }
        list_plane->plane = list_plane->plane->next;
    }
    list_plane->plane = temp;
}
