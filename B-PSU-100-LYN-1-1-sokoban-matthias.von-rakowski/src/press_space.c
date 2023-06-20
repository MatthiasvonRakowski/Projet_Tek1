/*
** EPITECH PROJECT, 2022
** press_space
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include "../include/my.h"

void press_space(map_arr_t *st_map)
{
    struct stat buf = st_map->buf;
    int fd = st_map->fd;
    char **av = st_map->av;

    for (int i = 0; st_map->map[i] != NULL; i++)
        free(st_map->map[i]);
    free(st_map->map);
    free(st_map);
    endwin();
    exit(main(2, av));
}
