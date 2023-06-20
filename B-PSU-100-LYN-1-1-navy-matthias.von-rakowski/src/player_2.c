/*
** EPITECH PROJECT, 2023
** player_2
** File description:
** you're a bad developer
*/

#include "../include/my.h"
#include <stdlib.h>

player_t *init_player(char *filepath)
{
    player_t *ele = malloc(sizeof(player_t));
    ele->map_player = init_map_player(filepath);
    ele->map_ennemy = init_map();
    ele->boat_en = 0;
    ele->boat_pl = 0;
    ele->code = 0;
    ele->pid = 0;
    return ele;
}

player_t *player_2(char *pid, char *filepath)
{
    player_t *player = init_player(filepath);
    player->pid = my_atoi(pid);
    return player;
}
