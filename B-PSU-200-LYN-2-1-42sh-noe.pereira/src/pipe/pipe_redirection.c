/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** pipe_redirection
*/

#include "pipe.h"
#include "../launch_command/function_launch_command.h"

/*
    NOTE:
        Link fd to the filepath (trunc if ">" & didn't trunc if ">>")
*/
static int set_fd_redir(int *fd, pipe_t *pipe_s)
{
    char temp[256];
    pipe_s->filepath = clean_str(pipe_s->filepath);
    if (access(pipe_s->filepath, R_OK | W_OK) != 0) {
        return (-1);
    }
    if (access(getcwd(temp, sizeof(temp)), R_OK | W_OK) != 0) {
        return (-1);
    }
    if (pipe_s->trunc == false) {
        fd[pipe_s->save_j - 1] = open(pipe_s->filepath, O_APPEND | O_RDWR |
        O_CREAT, S_IRUSR | S_IWUSR);
    }
    if (pipe_s->trunc == true) {
        fd[pipe_s->save_j - 1] = open(pipe_s->filepath, O_RDWR |
        O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    }
    return (0);
}

/*
    NOTE:
        Ici que les redirections (">", ">>") avec le pipe se passent
*/
int execute_pipe_redir(pipe_t *pipe_s, com_info *com_info,
h_info *history, ast_node *root)
{
    pid_t pid; int error = 0; int status = 0;
    if (set_fd_redir(pipe_s->fd, pipe_s) != 0)
        return (84);
    pid = fork();
    if (pid == 0) {
        dup2(pipe_s->fd[pipe_s->save_j - 2], STDIN_FILENO);
        dup2(pipe_s->fd[pipe_s->save_j - 1], STDOUT_FILENO);
        close(pipe_s->fd[pipe_s->save_j - 1]);
        close(pipe_s->fd[pipe_s->save_j - 2]);
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
