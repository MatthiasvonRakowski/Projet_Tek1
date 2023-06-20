/*
** EPITECH PROJECT, 2023
** shoot
** File description:
** you're a bad developer
*/

#include "../include/my.h"

void send_data(player_t *player, char data)
{
    for (int i = 2; i >= 0; i--) {
        usleep(100);
        if ((data >> i) & 1)
            kill(player->pid, SIGUSR2);
        else
            kill(player->pid, SIGUSR1);
    }
}

void shoot(player_t *player, char *code)
{
    char letter = code[0] - 'A';
    char number = code[1] - '1';

    send_data(player, letter);
    send_data(player, number);
}
