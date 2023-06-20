/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#pragma once

typedef struct pos_element_s {
    int x;
    int y;
    struct pos_element_s *next;
} pos_element_t;

typedef struct map_arr_s {
    struct stat buf;
    int size;
    int size_str;
    char **map;
    char **av;
    int fd;
    int x;
    int y;
    int win;
    int loose;
    pos_element_t *st;
} map_arr_t;
