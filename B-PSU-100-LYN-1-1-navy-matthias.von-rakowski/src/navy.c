/*
** EPITECH PROJECT, 2023
** src/navy
** File description:
** main Navy
*/

#include "../include/my.h"
#include <stdlib.h>

void print_h(void)
{
    my_putstr("USAGE\n    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n    first_player_pid: only for the 2nd player. ");
    my_putstr("Pid if the first player.\n    navy_positions: file representin");
    my_putstr("g the positions of the ships.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h")) {
        print_h();
        return 0;
    }
    if (!valid_expression(ac, av))
        return 84;
    my_printf("my_pid: ");
    my_printf("%d", getpid());
    player_t *player_info;
    if (ac == 2) {
        my_printf("\nwaiting for enemy connection...\n\n");
        player_info = player_1(av[1]);
        my_printf("enemy connected\n\n");
        return game_1(player_info);
    } else {
        return game_2(av[1], av[2]);
    }
}
