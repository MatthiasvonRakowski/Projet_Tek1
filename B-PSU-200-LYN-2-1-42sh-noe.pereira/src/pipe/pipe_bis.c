/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** pipe_bis
*/

#include "pipe.h"
#include "../launch_command/function_launch_command.h"


void set_tab(pipe_t *pipe_s, ast_node *root, com_info *com_info)
{
    pipe_s->tab_of_node[pipe_s->b] = root;
    pipe_s->tab_of_node[pipe_s->b + 1] = NULL;
    pipe_s->b++;
}
