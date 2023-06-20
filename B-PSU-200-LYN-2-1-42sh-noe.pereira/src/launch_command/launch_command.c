/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** lauch_command
*/
#include "../../include/sh42_include.h"

int execute_child_process_no_red(com_info *com_info, ast_node *node)
{
    int child_status; pid_t child_pro = fork();
    if (child_pro == -1) { perror("fork"); exit(84);
    }
    if (child_pro == 0) {
        if (execve(com_info->com, node->commands,
        com_info->envi) == -1) {
            check_arch(node);
            exit (1);
        }
    }
    if (child_pro > 0) waitpid(child_pro, &child_status, 0);
    int tg = WEXITSTATUS(child_status);
    int r = check_output(node, child_status, com_info);
    if (tg == 1 || r == 1) {
        com_info->return_value = 1;
        free(com_info->com);
        return (-1);
    }
    com_info->return_value = 0;
    free(com_info->com); return (tg);
}

int execute_command_no_red(ast_node *root, com_info *com_info,
h_info *history, s_42sh *sh)
{
    errno = 0;
    if (execute_build(root, com_info, history, sh) == 1)
        return (0);
    if (com_info->where == 1) {
        com_info->where = 0;
        where_function(root, com_info); return (0);
    }
    if (com_info->repeat == 1) {
        com_info->repeat = 0;
        if (repeat_function(root, com_info, history, sh) == 1)
            return (1);
        return (0);
    }
    if (com_info->alias == 1) {
        com_info->alias = 0;
        alias_function(root, com_info); return (0);
    }
    com_info->com = malloc(sizeof(char) * 500);
    command_line(com_info, root, 0);
    return (execute_child_process_no_red(com_info, root));
}

int buildin(ast_node *root, com_info *com_info, h_info *history,
s_42sh *sh)
{
    if (check_if_i_do(com_info, root) == 1)
        return (1);
    if (strcmp(root->commands[0], "exit") == 0) {
        free_all(history, com_info, sh, 0);
        exit(0);
    }
    if (!strcmp(root->commands[0], "repeat"))
        com_info->repeat = 1;
    if (strcmp(root->commands[0], "setenv") == 0)
        com_info->setenv = 1;
    if (strcmp(root->commands[0], "unsetenv") == 0)
        com_info->unsetenv = 1;
    if (strcmp(root->commands[0], "cd") == 0)
        com_info->cd = 1;
    if (strcmp(root->commands[0], "history") == 0)
        com_info->history = 1;
    if (!strcmp(root->commands[0], "where"))
        com_info->where = 1;
    buildin_next(root, com_info, history, sh);
    return (execute_command_no_red(root, com_info, history, sh));
}

void parcour_tree(ast_node *root, com_info *com_info, h_info *history,
s_42sh *sh)
{
    if (root == NULL)
        return;
    switch (root->type) {
        case 1 : launch_redirection_r(root->f_g, root->f_d,
            com_info, true); break;
        case 2 : launch_redirection_r(root->f_g, root->f_d,
            com_info, false); break;
        case 3 : launch_redirection_l(root->f_g, root->f_d,
            com_info); break;
        case 10 : if (!root->father || root->father->type == 6
        || root->father->type == 5) buildin(root, com_info,
        history, sh); break;
        default: break;
    }
    parcour_tree(root->f_g, com_info, history, sh);
    parcour_tree(root->f_d, com_info, history, sh);
}

void launch_command(s_42sh *sh_42, com_info *com_info, h_info *history)
{
    com_info->return_value = 0;
    for (int i = 0; i < sh_42->nb_com; i++) {
        lauch_pipe(sh_42->head->sons[i], com_info, history, sh_42);
        parcour_tree(sh_42->head->sons[i], com_info, history, sh_42);
    }
}
