/*
** EPITECH PROJECT, 2023
** src/answer
** File description:
** example of bad code:
*/

#include "../include/my.h"
#include <signal.h>

void answer(player_t *player, char *code)
{
    int hit_or_miss;
    signal(SIGUSR1, &recieved_handler);
    signal(SIGUSR2, &recieved_handler);
    pause();
    hit_or_miss = signal_receiving(-1);
    if (hit_or_miss == 1) {
        player->map_ennemy[code[0] - 'A'][code[1] - '1'] = 'x';
        my_printf("%c%c: hit\n\n", code[0], code[1]);
        player->boat_pl++;
    } else {
        player->map_ennemy[code[0] - 'A'][code[1] - '1'] = 'o';
        my_printf("%c%c: missed\n\n", code[0], code[1]);
    }
}
