/*
** EPITECH PROJECT, 2023
** src/generator_manager
** File description:
** valid expression
*/

#include "../include/my.h"

void free_struct_maze(struct maze **s_maze)
{
    for (int i = 0; s_maze[i] != NULL; i++)
        free(s_maze[i]);
    free(s_maze);
}

void free_maze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        free(maze[i]);
    free(maze);
}
