/*
** EPITECH PROJECT, 2023
** src/generator_perfect
** File description:
** make a perfect maze
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    char **maze;
    struct global *global;
    struct op_list *act;

    if (ac != 2)
        exit(84);
    maze = get_maze(av[1]);
    global = init_global(maze);
    append_element(&global->s_maze[0][0], global->oplist);
    a_star(&global, maze);
    free_struct_maze(global->s_maze);
    free_list(global->oplist);
    free(global);
}
