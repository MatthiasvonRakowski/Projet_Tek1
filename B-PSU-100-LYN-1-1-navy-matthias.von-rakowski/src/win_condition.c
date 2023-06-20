/*
** EPITECH PROJECT, 2023
** src/wait_pid
** File description:
** wait pid
*/

#include "../include/my.h"

int win_condition(player_t *player_info)
{
    if (player_info->boat_pl == 14) {
        maps_print(player_info);
        my_printf("I won\n");
        return 0;
    } else {
        maps_print(player_info);
        my_printf("Enemy won\n");
        return 1;
    }
}
