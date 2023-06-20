/*
** EPITECH PROJECT, 2023
** include/generator
** File description:
** make a generator with a .h
*/

#pragma once

////////////////////////////////////INCLUDE/////////////////////////////////////

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

////////////////////////////////////STRUCT//////////////////////////////////////

/////////////////////////////////////LIB////////////////////////////////////////

int my_str_is_num(char *str);

//////////////////////////////////PROGRAMM//////////////////////////////////////

int generator_perfect(int x, int y);
void modify_arr(int **arr, int x, int y, int data[3]);
int generator_imperfect(int x, int y);
void create_maze(int **arr, int *dim, int **indic);
int **shuffle_list (int **indic, int size);
int **map_malloc(int *dimension, int ***indic);
void print_maze(int **arr, int *dimension);
