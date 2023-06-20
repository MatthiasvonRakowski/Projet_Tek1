/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** hey. real programmers use vim
*/

#pragma once

#include "struct.h"

/*-----------------------------------LIB--------------------------------------*/

void my_putchar(char c);
void my_putstr(char *str);

/*----------------------------------PROGRAM-----------------------------------*/

void press_space(map_arr_t *st_map);
void game_begin(map_arr_t *st_map);
void check_if_o(map_arr_t *st_map);
void end_game(map_arr_t *st_map);
void do_we_win(map_arr_t *st_map);
int check_box(map_arr_t *st_map, int i, int j);
void do_we_loose(map_arr_t *st_map);
void map_mooving(int ch, map_arr_t *st_map);
void press_space(map_arr_t *st_map);
map_arr_t *game_init(map_arr_t *st_map);
char **my_str_to_word_array_info(char *map, int *size, int *size_str);
int main(int ac, char **av);
