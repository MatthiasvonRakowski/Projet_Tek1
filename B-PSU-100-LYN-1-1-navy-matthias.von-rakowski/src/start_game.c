/*
** EPITECH PROJECT, 2023
** start_game
** File description:
** you're a bad developer
*/

#include "../include/my.h"

void attack(player_t *player_info, char *code)
{
    size_t size_code = 3;

    do {
        my_printf("attack: ");
        getline(&code, &size_code, stdin);
    } while (!valid_code(code));
    shoot(player_info, code);
    answer(player_info, code);
}

void defence(player_t *player_info)
{
    my_printf("waiting for attack...\n");
    set_signal();
    player_info->code = 0;
    while (protocol_signal(0) == -1)
        usleep(100);
    player_info->code = protocol_signal(1);
    hit_or_miss(player_info);
}

int game_1(player_t *player_info)
{
    set_signal();
    size_t size_code = 3;
    char *code = malloc(sizeof(char) * (size_code + 1));

    while (player_info->boat_pl < 14 && player_info->boat_en < 14) {
        maps_print(player_info);
        attack(player_info, code);
        if (player_info->boat_pl >= 14 || player_info->boat_en >= 14)
            break;
        defence(player_info);
    }
    return win_condition(player_info);
}

int game_2(char *pid, char *mapfile)
{
    if (!valid_connection(pid))
        return 84;
    player_t *player_info = player_2(pid, mapfile);
    my_printf("\nsuccessfully connected\n\n");
    set_signal();
    size_t size_code = 3;
    char *code = malloc(sizeof(char) * (size_code + 1));

    while (player_info->boat_pl < 14 && player_info->boat_en < 14) {
        set_signal();
        maps_print(player_info);
        defence(player_info);
        if (player_info->boat_pl >= 14 || player_info->boat_en >= 14)
            break;
        attack(player_info, code);
    }
    return win_condition(player_info);
}
