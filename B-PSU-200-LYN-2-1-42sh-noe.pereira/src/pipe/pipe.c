/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** pipe
*/

#include "pipe.h"
#include "../launch_command/function_launch_command.h"

/*
    NOTE: Permet de lancer l'execution des pipe si il y en a
*/
int lauch_pipe(ast_node *root, com_info *com_info,
h_info *history, s_42sh *sh_42)
{
    pipe_t *s_pipe = malloc(sizeof(pipe_t));
    s_pipe->redir = false;
    s_pipe->nb_pipe = count_pipe(root, 0, s_pipe);
    if (s_pipe->nb_pipe != 0) {
        s_pipe->a = 0; s_pipe->b = 0; s_pipe->c = 0;
        s_pipe->sh = sh_42;
        s_pipe->tab_of_node = malloc(sizeof(ast_node) * (s_pipe->nb_pipe + 2));
        parcour_tree_pipe(root, com_info, s_pipe);
        pipe_exe(com_info, s_pipe, history);
        free_pipe(s_pipe);
        return (1);
    } else {
        free(s_pipe);
        return (0);
    }
}

/*
    NOTE:
        Compte le nombre de commande a passé dans un pipe
        et check si il y a une redirection
    Ex:
        ls | cat -e                         (renvoie 1)
        ls | cat -e | cat -e >> temp.txt    (renvoie 2)
        le | cat -e | cat -e                (renvoie 2)
*/
int count_pipe(ast_node *root, int i, pipe_t *s_pipe)
{
    if (root == NULL)
        return i;
    if (root->type == 0)
        i++;
    if (root->type == 1 || root->type == 2) {
        s_pipe->redir = true;
        s_pipe->filepath = root->f_d->com_line;
        if (root->type == 1)
            s_pipe->trunc = true;
        if (root->type == 2)
            s_pipe->trunc = false;
    }
    i = count_pipe(root->f_g, i, s_pipe);
    i = count_pipe(root->f_d, i, s_pipe);
    return i;
}

/*
    NOTE:
        Cette fonction permet de créer un tableau (tab_of_pipe_cmd) étant
        un tableau de deuxieme parametre de execve()
        et un tableau (tab_of_com) étant un tableau de premier paramètre de
        execve()
*/
void parcour_tree_pipe(ast_node *root, com_info *com_info, pipe_t *pipe_s)
{
    if (root == NULL) {
        return;
    }
    if (root->type == 10 && root->father->type == 0 && root->check == 0) {
        set_tab(pipe_s, root, com_info);
        root->type = -1;
    }
    if ((root->type == 1 || root->type == 2) && root->check == 0) {
        set_tab(pipe_s, root->f_g, com_info);
        root->type = -1;
    }
    parcour_tree_pipe(root->f_g, com_info, pipe_s);
    parcour_tree_pipe(root->f_d, com_info, pipe_s);
}

/*
    NOTE: ici que les redirections avec dup2() et l'execution avec execve()
    sont faites
*/
int execute_process(pipe_t *pipe_s, com_info *com_info,
h_info *history , ast_node *root)
{
    pid_t pid;
    int status = 0; int error = 0;
    if (com_info->return_value) return (0);
    pid = fork();
    if (pid == 0) {
        if (pipe_s->next_cmd_exist == 1)
            dup2(pipe_s->fd[pipe_s->save_j + 1], 1);
        if (pipe_s->save_j != 0)
            dup2(pipe_s->fd[pipe_s->save_j - 2], 0);
        for (int i = 0; i < 2 * (pipe_s->nb_pipe + 1); i++)
            close(pipe_s->fd[i]);
        error = buildin(root, com_info, history, pipe_s->sh);
        exit(error);
    } else {
        usleep(10000);
        pid_t child = waitpid(-1, &status, WNOHANG);
        if (WEXITSTATUS(status) != 0)
            return (84);
    }
    return (0);
}

/*
    NOTE: Pipe le nombre de fois qui le faut puis lance le processusc de dup2()
*/
void pipe_exe(com_info *com_info, pipe_t *pipe_s, h_info *history)
{
    if (pipe_s->redir == true)
        pipe_s->nb_pipe++;
    pipe_s->fd = malloc(sizeof(int) * ((pipe_s->nb_pipe + 1) * 2));
    pipe_s->num = 0;
    for (int i = 0; i < pipe_s->nb_pipe + 1; i++) {
        if (pipe(pipe_s->fd + i * 2) < 0) exit(1);
    }
    pipe_s->save_j = 0;

    while (pipe_s->tab_of_node[pipe_s->c] != NULL) {
        if (pipe_exe_next(pipe_s, com_info, history) == 84) {
            com_info->return_value = 1;
            return;
        }
        pipe_s->save_j += 2; pipe_s->num++; pipe_s->c++;
    }
    for (int i = 0; i < 2 * (pipe_s->nb_pipe + 1); i++) close(pipe_s->fd[i]);
    if (pipe_s->redir == false) {
        for (int i = 0; i < (pipe_s->nb_pipe + 2); i++) wait(NULL);
    }
}
