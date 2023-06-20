/*
** EPITECH PROJECT, 2022
** game_init
** File description:
** there's a problem: the intra is not down
*/

#include "../include/my.h"

void init_stor(map_arr_t *st_map, int x, int y)
{
    pos_element_t *temp;

    temp = malloc(sizeof(pos_element_t));
    temp->x = x;
    temp->y = y;
    temp->next = st_map->st;
    st_map->st = temp;
}

int info_map_char(map_arr_t *st_map, int x, int y, char c)
{
    if (c == 'X' && st_map->map[x][y] == c)
        return 1;
    if (c == 'O' && st_map->map[x][y] == c) {
        init_stor(st_map, x, y);
        return 1;
    }
    if (st_map->map[x][y] == 'P' && (st_map->x != 0 || st_map->y != 0))
        exit(84);
    if (c == 'P' && st_map->map[x][y] == c) {
        st_map->x = x;
        st_map->y = y;
    }
    return 0;
}

void find_p(map_arr_t *st_map)
{
    int count_x = 0;

    st_map->x = 0;
    st_map->y = 0;
    st_map->win = 0;
    st_map->st = NULL;
    for (int x = 0; st_map->map[x] != NULL; x++)
        for (int y = 0; st_map->map[x][y] != '\0'; y++) {
            count_x += info_map_char(st_map, x, y, 'X');
            st_map->win += info_map_char(st_map, x, y, 'O');
            info_map_char(st_map, x, y, 'P');
        }
    if (count_x != st_map->win) {
        exit(84);
    }
}

map_arr_t *game_init(map_arr_t *st_map)
{
    char *map;

    map = malloc(sizeof(char) * st_map->buf.st_size + 1);
    read(st_map->fd, map, st_map->buf.st_size);
    st_map->map =
        my_str_to_word_array_info(map, &st_map->size, &st_map->size_str);

    find_p(st_map);
    return st_map;
}
