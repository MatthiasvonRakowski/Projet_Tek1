/*
** EPITECH PROJECT, 2022
** game_begin
** File description:
** begin the game
*/

#include "../include/my.h"

void game_begin(map_arr_t *st_map)
{
    int ch;

    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        for (int i = 0; st_map->map[i] != NULL; i++)
            mvprintw(i, 0, "%s", st_map->map[i]);
        refresh();
        do_we_win(st_map);
        do_we_loose(st_map);
        while ((ch = getch()) == ERR);
        map_mooving(ch, st_map);
    }
}
