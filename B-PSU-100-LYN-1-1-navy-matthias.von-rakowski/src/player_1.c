/*
** EPITECH PROJECT, 2023
** player_1
** File description:
** you're a bad developer
*/

#include "../include/my.h"

player_t *player_1(char *filepath)
{
    player_t *player = init_player(filepath);
    wait_pid(&player);
    return player;
}
