/*
** EPITECH PROJECT, 2023
** include/struct
** File description:
** struch and include
*/

#pragma once

typedef struct player_s {
    int pid;
    char **map_player;
    char **map_ennemy;
    int boat_pl;
    int boat_en;
    char code;
} player_t;
