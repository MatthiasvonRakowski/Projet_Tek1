/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** My lib
*/

#pragma once
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct coor_s {
    short x;
    short y;
    short nbr;
    short mem_x;
    short mem_y;
    int k;
    short size_str;
    short size;
    int t_size;
} coor_t;

void my_putchar(char c);
void creat_arr(coor_t *pos, char *buffer, char **arr, int size);
void init(coor_t *pos);
int my_getnbr(char *str, coor_t *pos);
int my_strlen(char *str);
void smaller(short **nb_arr, coor_t *pos);
void solucer(char **arr, coor_t *pos);
void my_putsol(char **arr, coor_t *pos, int i, int k);
void free_2d_c(char **arr, int size);
void free_2d_i(int **arr, int size);
char *init_getmap(char *filename, int fd, char *buffer);
coor_t *init_plus(char **arr, int **nb_arr, int size, int k);
void reinit(char **arr, coor_t *pos);
int my_getnbr_rec(char *str);
int point_or_nbr(short **nb_arr, char **arr, char c, coor_t *pos);
int create_conding_style(char *str, short **nb_arr, char **arr, coor_t *pos);
