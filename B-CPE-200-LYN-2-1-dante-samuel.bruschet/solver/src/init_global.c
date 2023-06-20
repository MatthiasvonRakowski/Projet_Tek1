/*
** EPITECH PROJECT, 2023
** src/generator_perfect
** File description:
** make a perfect maze
*/

#include "../include/my.h"

struct global *init_global(char **maze)
{
    struct global *global;
    struct head **oplist = malloc(sizeof(struct head *));

    *oplist = malloc(sizeof(struct head));
    (*oplist)->head = NULL;
    global = malloc(sizeof(struct global));
    global->oplist = oplist;
    global->x = 0;
    global->y = strlen(maze[0]) - 1;
    global->s_maze = struct_from_maze(maze, &global->x);
    return global;
}
