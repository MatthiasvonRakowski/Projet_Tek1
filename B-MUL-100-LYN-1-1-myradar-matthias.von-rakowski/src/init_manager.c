/*
** EPITECH PROJECT, 2022
** init_manager
** File description:
** init data
*/

#include "../include/my.h"

int secu_check(void *secu)
{
    if (secu == NULL) {
        return 0;
    }
    return 1;
}

int init_from_txt(data_t *data, FILE *fd)
{
    char *buff;
    size_t size = 0;
    int secu = 1;

    data->list_plane = init_first_list_plane();
    while (getline(&buff, &size, fd) != -1) {
        if (buff[0] == 'A') {
            data->list_plane = init_plane(&buff[2], data->list_plane);
            secu = secu_check(data->list_plane->plane);
        }
        if (buff[0] == 'T') {
            data->tower = init_tower(&buff[2], data->tower);
            secu = secu_check(data->tower);
        }
        if ((buff[0] != 'A' && buff[0] != 'T') || secu == 0)
            return 0;
    }
    return 1;
}

norme_t init_norme(void)
{
    norme_t data;

    data.timer = 0.0;
    data.time_speed = 1;
    data.mode = (sfVideoMode) {MAP_WIDTH, MAP_HEIGHT, 32};
    data.window = sfRenderWindow_create(data.mode, "my_radar", sfDefaultStyle,
    NULL);
    data.clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(data.window, 60);
    return data;
}

grid_t *init_grid(sfFloatRect box, int level)
{
    grid_t *grid = malloc(sizeof(grid_t));

    grid->nb_plane = 0;
    grid->level = level;
    grid->box = box;
    grid->plane = NULL;
    grid->next = NULL;
    grid->inside = NULL;
    return grid;
}

data_t *init_data(FILE *fd)
{
    data_t *data;

    data = malloc(sizeof(data_t));
    data->norme = init_norme();
    data->text = init_text();
    if (init_from_txt(data, fd) == 0)
        return NULL;
    data->grid = init_grid((sfFloatRect) {-20, -20, MAP_WIDTH + 40,
    MAP_HEIGHT + 40}, 0);
    data->draw = init_draw();
    return data;
}
