/*
** EPITECH PROJECT, 2022
** loose_or_win
** File description:
** M-x doctor
*/

#include "../include/my.h"

void check_if_o(map_arr_t *st_map)
{
    pos_element_t *temp = st_map->st;

    while (temp) {
        if (st_map->map[temp->x][temp->y] == ' ')
            st_map->map[temp->x][temp->y] = 'O';
        temp = temp->next;
    }
}

void end_game(map_arr_t *st_map)
{
    for (int i = 0; st_map->map[i] != NULL; i++) {
        my_putstr(st_map->map[i]);
        my_putchar('\n');
        free(st_map->map[i]);
    }
    free(st_map->map);
    free(st_map);
}

void do_we_win(map_arr_t *st_map)
{
    int count_win = 0;
    pos_element_t *temp = st_map->st;

    while (temp) {
        if (st_map->map[temp->x][temp->y] == 'X')
            count_win++;
        temp = temp->next;
    }
    if (st_map->win == count_win) {
        endwin();
        end_game(st_map);
        exit(0);
    }
}

int check_box(map_arr_t *st_map, int i, int j)
{
    if (i > 0 && j > 0 && st_map->map[i][j] == 'X') {
        if ((st_map->map[i - 1][j] == 'X' || st_map->map[i - 1][j] == '#' ||
            st_map->map[i + 1][j] == 'X' || st_map->map[i + 1][j] == '#') &&
            (st_map->map[i][j - 1] == 'X' || st_map->map[i][j - 1] == '#' ||
            st_map->map[i][j + 1] == 'X' || st_map->map[i][j + 1] == '#')) {
            return 1;
        }
    }
    return 0;
}

void do_we_loose(map_arr_t *st_map)
{
    int nbr_of_blk = 0;

    for (int i = 0; st_map->map[i] != NULL; i++)
        for (int j = 0; st_map->map[i][j] != '\0'; j++) {
            nbr_of_blk += check_box(st_map, i, j);
        }
    if (nbr_of_blk == st_map->win) {
        endwin();
        end_game(st_map);
        exit(1);
    }
}
