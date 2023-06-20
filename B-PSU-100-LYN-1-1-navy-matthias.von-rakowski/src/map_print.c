/*
** EPITECH PROJECT, 2023
** src/map_print
** File description:
** map print
*/

#include "../include/my.h"

void print_one_map(char **map)
{
    for (int i = 0; i < MAP_HEIGHT; i++) {
        my_putchar(i + '1');
        my_putchar('|');
        for (int j = 0; j < MAP_WIDTH - 1; j++) {
            my_putchar(map[j][i]);
            my_putchar(' ');
        }
        my_putchar(map[MAP_WIDTH - 1][i]);
        my_putchar('\n');
    }
}

void maps_print(player_t *player)
{
    my_putstr("my positions:\n |A B C D E F G H\n-+---------------\n");
    print_one_map(player->map_player);
    my_putstr("\nenemy's positions:\n |A B C D E F G H\n-+---------------\n");
    print_one_map(player->map_ennemy);
    my_printf("\n");
}
