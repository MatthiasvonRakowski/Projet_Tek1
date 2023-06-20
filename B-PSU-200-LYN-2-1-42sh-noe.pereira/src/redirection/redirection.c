/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** redirection
*/

#include "redirection.h"
#include "../launch_command/function_launch_command.h"

/*
    NOTE:
        Link fd to the filepath (trunc if ">" & didn't trunc if ">>")
*/
static int set_fd(int *fd, bool trunc, char *filepath)
{
    char temp[256];
    filepath = clean_str(filepath);
    if (access(filepath, R_OK | W_OK) != 0) {
        printf("%s: Permission denied.\n", filepath);
        return (-1);
    }
    if (access(getcwd(temp, sizeof(temp)), R_OK | W_OK) != 0) {
        printf("%s: Permission denied.\n", filepath);
        return (-1);
    }
    if (trunc == false) {
        *fd = open(filepath, O_APPEND | O_WRONLY |
        O_CREAT, 0644);
    }
    if (trunc == true) {
        *fd = open(filepath, O_WRONLY |
        O_CREAT | O_TRUNC, 0644);
    }
    return (0);
}

/*
    NOTE:
        Allow ">" & ">>" execution
*/
void launch_redirection_r(ast_node *l_son, ast_node *r_son, com_info *com_info,
bool trunc)
{
    int fd; pid_t pid;

    if (set_fd(&fd, trunc, r_son->com_line) == -1)
        return;
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        close(fd);
        com_info->com = malloc(sizeof(char) * 500);
        command_line(com_info, l_son, 0);
        if (execve(com_info->com, l_son->commands, com_info->envi)) {
            exit (1);
        }
    }
    if (pid > 0) {
        wait(NULL);
    }
}

void launch_redirection_l(ast_node *l_son, ast_node *r_son, com_info *com_info)
{
    char *filepath = clean_str(r_son->com_line);
    int fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        write(1, filepath, strlen(filepath));
        write(1, ": No such file or directory.\n", 29);
        return;
    }
    pid_t pid = fork();
    if (pid == 0) {
        dup2(fd, 0); close(fd); close(STDIN_FILENO);
        com_info->com = malloc(sizeof(char) * 500);
        command_line(com_info, l_son, 0);
        if (execve(com_info->com, l_son->commands, com_info->envi)) {
            exit (1);
        }
    }
    if (pid > 0) {
        close(fd);
        wait(NULL);
    }
}
