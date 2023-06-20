/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** check_error
*/
#include "../../include/sh42_include.h"

int check_folder(ast_node *node, com_info *com_info)
{
    char *str5 = ": Permission denied.\n";
    struct stat *folder = malloc(sizeof(struct stat));
    stat(com_info->com, folder);

    if (S_ISDIR(folder->st_mode)) {
        write(2, node->commands[0], strlen(node->commands[0]));
        write(2, str5, strlen(str5));
        free(folder);
        return (1);
    }
    free(folder);
    return (0);
}

int check_output_next(ast_node *node, int h, int n, int yo)
{
    char *str1 = "Segmentation fault\n";
    char *str = "Segmentation fault (core dumped)\n";
    if (h == 1 && yo == 0) {
        write(2, str1, strlen(str1)); return (1);
    }
    if (h == 1 && yo == 128) {
        write(2, str, strlen(str)); return (1);
    }
    return (0);
}

int check_output(ast_node *node, int child_status, com_info *com_info)
{
    if (check_folder(node, com_info) == 1) return (1);
    int h = WIFSIGNALED(child_status);
    int tg = WTERMSIG(child_status);
    int yo = __WCOREDUMP(child_status);
    char *str5 = ": Permission denied.\n";
    char *str6 = "Floating exception\n";
    char *str7 = "Floating exception (core dumped)\n";
    if (tg == SIGFPE && yo == 0) {
        write(2, str6, strlen(str6)); return (1);
    }
    if (tg == SIGFPE && yo == 128) {
        write(2, str7, strlen(str7)); return (1);
    }
    if (errno == 8 || errno == 2) return (0);
    if (errno == EACCES) {
        write(2, node->commands[0], strlen(node->commands[0]));
        write(2, str5, strlen(str5)); return (1);
    }
    if (check_output_next(node, h, tg, yo) == 1) return (1);
    return (0);
}

void check_arch(ast_node *node)
{
    char *str4 = ": Exec format error. Wrong Architecture.\n";
    if (errno == 8) {
        write(2, node->commands[0], strlen(node->commands[0]));
        write(2, str4, strlen(str4));
        return;
    }
    if (errno == 2) {
        char *str2 = ": Command not found.\n";
        write(2, node->commands[0], strlen(node->commands[0]));
        write(2, str2, strlen(str2));
        return;
    }
}
