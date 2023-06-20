/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pipe_next
*/
#include "../../include/sh42_include.h"

int pipe_exe_next(pipe_t *pipe_s, com_info *com_info,
h_info *history)
{
    pipe_s->next_cmd_exist =
    (pipe_s->tab_of_node[pipe_s->c + 1] == NULL) ? 0 : 1;
    if (pipe_s->redir == true &&
    pipe_s->tab_of_node[pipe_s->c + 1] == NULL)
        if (execute_pipe_redir(pipe_s, com_info, history,
        pipe_s->tab_of_node[pipe_s->c]) == 84)
            return (84);
    if (pipe_s->redir == true &&
    pipe_s->tab_of_node[pipe_s->c + 1] != NULL)
        if (execute_process(pipe_s, com_info, history,
        pipe_s->tab_of_node[pipe_s->c]) == 84)
            return (84);
    if (pipe_s->redir == false)
        if (execute_process(pipe_s, com_info, history,
        pipe_s->tab_of_node[pipe_s->c]) == 84)
            return (84);
    return (0);
}
