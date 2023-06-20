/*
** EPITECH PROJECT, 2022
** music_change
** File description:
** music change
*/

#include "include/my.h"

void music_change(sfMusic **music, int chanel)
{
    for(int i = 0; i < 5; i++)
        if (sfMusic_getStatus(music[i]) == sfPlaying) {
            sfMusic_stop(music[i]);
            sfMusic_play(music[chanel]);
            return;
        }
}
