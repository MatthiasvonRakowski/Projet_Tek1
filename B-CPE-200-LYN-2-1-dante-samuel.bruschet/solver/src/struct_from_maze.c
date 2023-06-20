/*
** EPITECH PROJECT, 2023
** src/generator_manager
** File description:
** get_maze
*/

#include "../include/my.h"

int my_str2dlen(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}

struct maze init_one_char(char c, int i, int j)
{
    struct maze m;

    m.parent = NULL;
    m.open = 0;
    m.c = c;
    m.i = i;
    m.j = j;
    m.f = 0;
    m.g = 0;
    return m;
}

struct maze **struct_from_maze(char **maze, int *len)
{
    int len_line = strlen(maze[0]);
    struct maze **s_maze;

    *len = my_str2dlen(maze);
    s_maze = malloc(sizeof(struct maze*) * (*len + 1));
    for (int i = 0; maze[i] != NULL; i++) {
        len_line = strlen(maze[i]);
        s_maze[i] = malloc(sizeof(struct maze) * (len_line));
        for (int j = 0; j < len_line - 1; j++)
            s_maze[i][j] = init_one_char(maze[i][j], i, j);
        s_maze[i][len_line - 1] = init_one_char(maze[i][len_line],
                                                    i, len_line - 1);
    }
    s_maze[*len] = NULL;
    return s_maze;
}
