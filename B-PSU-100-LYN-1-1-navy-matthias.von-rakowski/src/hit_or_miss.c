/*
** EPITECH PROJECT, 2023
** src/hit_or_miss
** File description:
** there's a problem: the intra is not down
*/

#include "../include/my.h"

int verif_touch(player_t *player, int letter, int nbr)
{
    if (player->map_player[letter][nbr] >= '0' &&
        player->map_player[letter][nbr] <= '9')
        return 1;
    return 0;
}

char good_letter(player_t *player, int letter, int nbr)
{
    if (player->map_player[letter][nbr] == 'x')
        return 'x';
    return 'o';
}

void hit_or_miss(player_t *player)
{
    int letter = (player->code >> 3);
    int nbr = 0;

    if ((player->code >> 2) & 1)
        nbr += 4;
    if ((player->code >> 1) & 1)
        nbr += 2;
    if (player->code & 1)
        nbr += 1;
    if (verif_touch(player, letter, nbr)) {
        my_printf("%c%c: hit\n\n", letter + 'A', nbr + '1');
        player->map_player[letter][nbr] = 'x';
        player->boat_en++;
        kill(player->pid, SIGUSR2);
    } else {
        my_printf("%c%c: missed\n\n", letter + 'A', nbr + '1');
        player->map_player[letter][nbr] = good_letter(player, letter, nbr);
        kill(player->pid, SIGUSR1);
    }
}
