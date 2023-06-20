/*
** EPITECH PROJECT, 2022
** update_manager
** File description:
** there's a problem: the intra is not down
*/

#include "../include/my.h"
#include <SFML/Graphics/Rect.h>

void update_text(norme_t norme, text_t *text)
{
    char *temp;
    free(text->str_timer);
    free(text->str_time_speed);
    text->str_timer = my_transform_float_in_str(norme.timer, 2);
    temp = my_transform_float_in_str(norme.time_speed, 0);
    text->str_time_speed = my_strcat("x", temp);
    free(temp);
}

grid_t *place_and_count(plane_t *plane, grid_t *grid, tower_t *tower,
double timer)
{
    void *temp = grid->inside;

    while (grid->inside) {
        place(plane, grid, &grid->nb_plane, timer);
        grid->inside = grid->inside->next;
    }
    return temp;
}

void algo(grid_t *grid, plane_t *plane_ori, tower_t *tower, double timer)
{
    void *temp = plane_ori;
    if (grid->nb_plane > 50 && grid->level < 0) {
        grid->inside = creat_grid(grid);
        grid->inside = place_and_count(plane_ori, grid, tower, timer);
        while (grid->inside) {
            algo(grid->inside, plane_ori, tower, timer);
            grid->inside = grid->inside->next;
        }
    } else {
        while (plane_ori) {
            check_colision(plane_ori, tower, timer);
            plane_ori = plane_ori->next;
        }
        plane_ori = temp;
    }
    while (grid->inside) {
        temp = grid->inside->next;
        free(grid->inside);
        grid->inside = temp;
    }
}

void update_grid(list_plane_t *list, grid_t *grid, tower_t *tower, double timer)
{
    grid->nb_plane = list->nb_plane;
    algo(grid, list->plane, tower, timer);
}

void update_manager(data_t *data)
{
    update_plane_manager(data->list_plane, data->tower, data->norme);
    update_grid(data->list_plane, data->grid, data->tower, data->norme.timer);
    update_text(data->norme, data->text);
}
