/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** try not to segfault, good luck :)
*/

#include "struct.h"

#pragma once

/*----------------------------------DEFINE------------------------------------*/

#define MAP_HEIGHT 1080
#define MAP_WIDTH 1920

/*------------------------------------LIB-------------------------------------*/

int my_str_isnum (char const *str);
int my_compute_power(int nbr, int power);
int my_getnbr(char *str);
int my_strlen(char *str);
int my_strcmp(char const *str, char const *cmp);
int my_getline_in_array(char const *str, int *arr, int size);
void my_putstr(char const *str);
char *my_transform_float_in_str(double db_nbr, int nb_after_comma);
char *my_strcat(char *dest, char *src);

/*--------------------------------PROGRAMM------------------------------------*/

sfCircleShape *create_circle(float radius);

/*---------------------------------DESTROY------------------------------------*/

void destroy_manager(data_t *data);
void destroy_plane(plane_t *plane);
void destroy_tower(tower_t *tower);
void destroy_list_plane(list_plane_t *list);
void destroy_draw(draw_t *draw);

/*-----------------------------------INIT-------------------------------------*/

data_t *init_data(FILE *fd);
grid_t *init_grid(sfFloatRect box, int level);
draw_t *init_draw(void);
text_t *init_text(void);
list_plane_t *init_first_list_plane(void);
list_plane_t *init_plane(char *buff, list_plane_t *list_plane);
data_t *init_data(FILE *fd);
tower_t *init_tower(char *buff, tower_t *tower);

/*---------------------------------UPDATE-------------------------------------*/

void update_manager(data_t *data);
void place(plane_t *plane, grid_t *grid, int *nb_plane, double timer);
void check_colision(plane_t *plane, tower_t *tower, float timer);
grid_t *creat_grid(grid_t *grid);
void update_plane_manager(list_plane_t *list_plane, tower_t *tower,
norme_t norme);

/*----------------------------------EVENT-------------------------------------*/

norme_t event_manager(data_t *data);

/*-----------------------------------DRAW-------------------------------------*/

void draw_manager(data_t *data);
void draw_plane(norme_t *norme, list_plane_t *list, draw_t *draw,
plane_t *prev);
