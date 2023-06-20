/*
** EPITECH PROJECT, 2023
** src/generator_perfect
** File description:
** make a perfect maze
*/

#ifndef B_CPE_200_LYN_2_1_DANTE_SAMUEL_BRUSCHET_MY_H
    #define B_CPE_200_LYN_2_1_DANTE_SAMUEL_BRUSCHET_MY_H
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <string.h>
    #include "maze.h"

// ------------------------- PROJECT ------------------------------

char **get_maze(char *pathfile);

int count_line(char *buffer);

void free_maze(char **maze);

struct maze **struct_from_maze(char **maze, int *len);

void append_element(struct maze *c, struct head **openlist);

void free_struct_maze(struct maze **s_maze);

struct op_list *pop_element(struct head **openlist);

void append_sorted(struct maze *c, struct head **openlist);

struct global *init_global(char **maze);

void apply_a_star(struct global **global, struct op_list *act,
                    int i, int j);

void print_list(struct head *oplist);

void free_list(struct head **oplist);

void victoire(struct global *global, char **maze);

void a_star(struct global **global, char **maze);

// ------------------------- PROJECT ------------------------------

#endif //B_CPE_200_LYN_2_1_DANTE_SAMUEL_BRUSCHET_MY_H
