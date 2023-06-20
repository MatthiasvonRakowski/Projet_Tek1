/*
** EPITECH PROJECT, 2022
** moove
** File description:
** all direction moove
*/

#include "../include/my.h"

void moove_up(map_arr_t *st_map)
{
    switch (st_map->map[st_map->x - 1][st_map->y]) {
        case '#': return;
        case 'O':
        case ' ': st_map->map[st_map->x - 1][st_map->y] = 'P';
            st_map->map[st_map->x][st_map->y] = ' ';
            break;
        case 'X': if (st_map->map[st_map->x - 2][st_map->y] == '#' ||
            st_map->map[st_map->x - 2][st_map->y] == 'X')
                return;
            st_map->map[st_map->x - 1][st_map->y] = 'P';
            st_map->map[st_map->x - 2][st_map->y] = 'X';
            st_map->map[st_map->x][st_map->y] = ' ';
            break;
    };
    st_map->x = st_map->x - 1;
}

void moove_down(map_arr_t *st_map)
{
    switch (st_map->map[st_map->x + 1][st_map->y]) {
        case '#': return;
        case 'O':
        case ' ': st_map->map[st_map->x + 1][st_map->y] = 'P';
            st_map->map[st_map->x][st_map->y] = ' ';
            break;
        case 'X': if (st_map->map[st_map->x + 2][st_map->y] == '#' ||
            st_map->map[st_map->x + 2][st_map->y] == 'X')
                return;
            st_map->map[st_map->x + 1][st_map->y] = 'P';
            st_map->map[st_map->x][st_map->y] = ' ';
            st_map->map[st_map->x + 2][st_map->y] = 'X';
            break;
    };
    st_map->x = st_map->x + 1;
}

void moove_left(map_arr_t *st_map)
{
    switch (st_map->map[st_map->x][st_map->y - 1]) {
        case '#': return;
        case 'O':
        case ' ': st_map->map[st_map->x][st_map->y - 1] = 'P';
            st_map->map[st_map->x][st_map->y] = ' ';
            break;
        case 'X': if (st_map->map[st_map->x][st_map->y - 2] == '#' ||
            st_map->map[st_map->x][st_map->y - 2] == 'X')
                return;
            st_map->map[st_map->x][st_map->y - 1] = 'P';
            st_map->map[st_map->x][st_map->y - 2] = 'X';
            st_map->map[st_map->x][st_map->y] = ' ';
            break;
    };
    st_map->y = st_map->y - 1;
}

void moove_right(map_arr_t *st_map)
{
    switch (st_map->map[st_map->x][st_map->y + 1]) {
        case '#': return;
        case 'O':
        case ' ': st_map->map[st_map->x][st_map->y + 1] = 'P';
            st_map->map[st_map->x][st_map->y] = ' ';
            break;
        case 'X': if (st_map->map[st_map->x][st_map->y + 2] == '#' ||
            st_map->map[st_map->x][st_map->y + 2] == 'X')
                return;
            st_map->map[st_map->x][st_map->y + 1] = 'P';
            st_map->map[st_map->x][st_map->y] = ' ';
            st_map->map[st_map->x][st_map->y + 2] = 'X';
            break;
    };
    st_map->y = st_map->y + 1;
}

void map_mooving(int ch, map_arr_t *st_map)
{
    switch (ch) {
        case KEY_UP: moove_up(st_map); break;
        case KEY_DOWN: moove_down(st_map); break;
        case KEY_LEFT: moove_left(st_map); break;
        case KEY_RIGHT: moove_right(st_map); break;
        case ' ': press_space(st_map); break;
        default: break;
    };
    check_if_o(st_map);
}
