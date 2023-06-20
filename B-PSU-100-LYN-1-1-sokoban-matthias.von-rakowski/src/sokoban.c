/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** Sokoban game
*/

#include "../include/my.h"

void put_help(void)
{
    my_putstr("USAGE\n    ./my_sokoban map\nDESCRIPTION\n    map  file");
    my_putstr("representing the warehouse map, containing '#' for walls,\n   ");
    my_putstr(" 'P' for the player, 'X' for boxes and 'O' for storage ");
    my_putstr("locations");

}

int main(int ac, char **av)
{
    map_arr_t *st_map;

    st_map = malloc(sizeof(map_arr_t));
    st_map->av = av;
    st_map->size = 0;
    st_map->size_str = 0;
    if (ac != 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h') {
            put_help();
            return 0;
    }
    if ((st_map->fd = open(av[1], O_RDONLY)) < 0) {
        close(st_map->fd);
        return 84;
    }
    fstat(st_map->fd, &st_map->buf);
    st_map = game_init(st_map);
    game_begin(st_map);
    return 0;
}
