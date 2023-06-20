/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** free_pipe
*/

#include "pipe.h"
#include "../launch_command/function_launch_command.h"

void free_pipe(pipe_t *pipe_s)
{
    free(pipe_s->fd);
    free(pipe_s->tab_of_node);
    free(pipe_s);
}
