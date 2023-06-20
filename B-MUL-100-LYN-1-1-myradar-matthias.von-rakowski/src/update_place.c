/*
** EPITECH PROJECT, 2023
** src/update_place
** File description:
** update place
*/

#include "../include/my.h"

void intersect(plane_t *plane, grid_t *grid, int *nb_plane)
{
    if (sfFloatRect_intersects(&plane->rect, &grid->box, NULL) ||
        sfFloatRect_contains(&grid->box, plane->rect.left,
        plane->rect.top)) {
        plane->level = grid->level;
        plane->box = grid->box;
        (*nb_plane)++;
    } else
        plane = plane->next;
}

void place(plane_t *plane, grid_t *grid, int *nb_plane, double timer)
{
    plane_t *temp = plane;

    while (plane) {
        if (plane->delay > timer) {
            plane = plane->next;
            continue;
        }
        if (*nb_plane > 50 && plane->level < 0) {
            plane = temp;
            return;
        }
        intersect(plane, grid, nb_plane);
    }
    plane = temp;
}
