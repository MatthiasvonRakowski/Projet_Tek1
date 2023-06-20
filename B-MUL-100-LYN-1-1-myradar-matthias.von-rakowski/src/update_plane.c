/*
** EPITECH PROJECT, 2023
** src/update_plane
** File description:
** update plane
*/

#include "../include/my.h"

int calc_p_t_y(float left, float top, int i, tower_t *tower)
{
    for (int j = 0; j < 21; j += 20)
        if (sqrt(pow((left + i) - tower->pos.x + 1, 2) +
        pow((top + j) - tower->pos.y + 1, 2)) < tower->radius)
            return 1;
    return 0;
}

int calc_p_t(float left, float top, tower_t *tower)
{
    for (int i = 0; i < 21; i += 20)
        if (calc_p_t_y(left, top, i, tower))
            return 1;
    return 0;
}

int under_control(plane_t *plane, tower_t *tower)
{
    void *temp_tower = tower;

    while (tower) {
        if (calc_p_t(plane->rect.left, plane->rect.top, tower))
            return 0;
        tower = tower->next;
    }
    tower = temp_tower;
    return 1;
}

void colision_scd_phase(plane_t *plane, tower_t *tower, float timer,
plane_t *temp)
{
    int ultim_check;
    while (temp) {
        if (temp->delay > timer) {
            temp = temp->next;
            continue;
        }
        if (sfFloatRect_intersects(&plane->rect, &temp->rect, NULL)) {
            ultim_check = under_control(temp, tower);
            plane->dead = ultim_check;
            temp->dead = ultim_check;
        }
        temp = temp->next;
    }
}

void check_colision(plane_t *plane, tower_t *tower, float timer)
{
    plane_t *temp = plane->next;
    int origin = plane->dead;

    if (plane->dist <= 0.0) {
        plane->dead = 1;
        return;
    }
    if (!(under_control(plane, tower))) {
        plane->dead = 0;
        plane->protect = 1;
        return;
    }
    plane->protect = 0;
    colision_scd_phase(plane, tower, timer, temp);
    if (origin)
        plane->dead = origin;
}
