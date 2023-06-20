/*
** EPITECH PROJECT, 2023
** include/my
** File description:
** my.h
*/

#pragma once
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*-----------------------------------DEFINE-----------------------------------*/

#define MAP_HEIGHT 8
#define MAP_WIDTH 8

/*----------------------------------LIB---------------------------------------*/

#include "../lib/include/my.h"
void my_putstr(char *str);
int my_strcmp(char const *str, char const *src);
int valid_script(char *scriptpath);
char **my_str_to_word_array(char *str);
int char_is_valid(char c);
int str_is_number(char *string);
int my_atoi(char *nb);

/*-------------------------------PROGRAMM-------------------------------------*/

void print_h(void);
int valid_expression(int ac, char **av);
int valid_script(char *scriptpath);
int valid_buffer(char *line, char *all_boat);
int valid_boats(char *line, char *all_boat);
int valid_pid(char *pid);
player_t *player_1(char *filepath);
player_t *player_2(char *nbr, char *filepath);
char **put_boat_in_map(char *buffer, char **map);
char **init_map_player(char *filepath);
char **init_map(void);
void start_game(player_t *player_info);
void signal_pid(int signal, siginfo_t *info, void *context);
player_t *init_player(char *filepath);
pid_t send_pid(siginfo_t *info);
void wait_pid(player_t **player);
void maps_print(player_t *player);
int valid_code(char *code);
void shoot(player_t *player, char *code);
char protocol_signal(int signal);
void set_signal(void);
void signal_handling(int signal);
int game_1(player_t *player_info);
int game_2(char *pid, char *mapfile);
int valid_connection(char *pid);
void apply_attack(player_t *player);
void hit_or_miss(player_t *player);
void recieved_handler(int signal);
int signal_receiving(int signal);
void answer(player_t *player, char *code);
int win_condition(player_t *player_info);
