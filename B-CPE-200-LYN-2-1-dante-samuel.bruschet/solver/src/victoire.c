/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-quentin.cialone
** File description:
** add_element.c
*/

#include "../include/my.h"

void print_maze(char **maze, int line_size)
{
    for (int i = 0; maze[i] != NULL; i++) {
        write(1, maze[i], line_size);
        if (maze[i + 1] != NULL)
            write(1, "\n", 1);
    }
}

void victoire(struct global *global, char **maze)
{
    struct maze *final_maze = &global->s_maze[global->x - 1][global->y - 1];

    while (final_maze->parent != NULL) {
        maze[final_maze->i][final_maze->j] = 'o';
        final_maze = final_maze->parent;
    }
    maze[final_maze->i][final_maze->j] = 'o';
    print_maze(maze, global->y);
    free_maze(maze);
}
