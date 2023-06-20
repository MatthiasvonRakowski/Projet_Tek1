/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** main
*/

#include "../include/struct_42sh.h"
#include "ast_tree/ast_tree_functions.h"
#include "launch_command/function_launch_command.h"
#include "history/history_functions.h"
#include "SYNTAX_ERROR/syntax_error.h"
#include "varenv/varenv.h"

int check_if_com(s_42sh *sh_42, int command_size)
{
    int siz = 0; int charr = 0;
    sh_42->com_line[command_size - 1] = '\0';
    for (int i = 0; sh_42->com_line[i] != '\0'; i++) {
        if (sh_42->com_line[i] == ' ' ||
        sh_42->com_line[i] == '\t')
            siz++;
        if (sh_42->com_line[i] != ' ' &&
        sh_42->com_line[i] != '\t')
            charr++;
    }
    if ((siz == 0 || siz == command_size - 1) && charr == 0)
        return (-1);
    return (1);
}

void cpy_env(com_info *com, char **env)
{
    int i = 0;
    int k = 0;
    int l = 0;
    for (; env[i] != NULL; i++) {
        k = 0;
        for (; env[i][k] != '\0'; k++);
        if (k > l) l = k;
    }
    com->size_env = i;
    com->envi = malloc(sizeof(char*) * (i + 1));
    for (int h = 0; h < i; h++)
        com->envi[h] = malloc(sizeof(char) * l + 1);
    i = 0;
    for (; env[i] != NULL; i++) {
        k = 0;
        for (; env[i][k] != '\0'; k++)
            com->envi[i][k] = env[i][k];
        com->envi[i][k] = '\0';
    }
    com->envi[i] = NULL;
}

void command(s_42sh *sh_42, com_info *com_info, h_info *history)
{
    init_var(sh_42, com_info, history); int error = 0;
    size_t size = 1000; int command_size, check;
    while (1) { check = 0; error = 0;
        if (isatty(0)) write(1, "$> ", 3);
        command_size = getline(&sh_42->com_line, &size, stdin);
        if (command_size == -1) return;
        error = detect_varenv(sh_42, com_info, history);
        command_size = strlen(sh_42->com_line);
        if (error == -1){ sh_42->com_line = NULL; continue;
        }
        if (error_syntax(sh_42->com_line) == true) continue;
        (check_if_com(sh_42, command_size) == -1) ? check = 1 : 0;
        if (check == 0)
            check = store_history_com(history, sh_42 ,command_size);
        if (check == 0) {
            store_dif_command(sh_42); create_tree(sh_42);
            launch_command(sh_42, com_info, history);
            free_tree(sh_42, com_info);
        }
    }
}

void get_buildins(com_info *com_info)
{
    for (int i = 0; i < 13; i++)
        com_info->built_in[i] = malloc(sizeof(char) * 10);
    com_info->built_in[0] = "cd";
    com_info->built_in[1] = "setenv";
    com_info->built_in[2] = "unsetenv";
    com_info->built_in[3] = "env";
    com_info->built_in[4] = "exit";
    com_info->built_in[5] = "echo";
    com_info->built_in[6] = "history";
    com_info->built_in[7] = "alias";
    com_info->built_in[8] = "unalias";
    com_info->built_in[9] = "where";
    com_info->built_in[10] = "which";
    com_info->built_in[11] = "repeat";
    com_info->built_in[12] = NULL;
}

//    //\\ set com_info value a 00000 !!
int main(int argc, char **agrv, char **env)
{
    s_42sh *sh_42 = malloc(sizeof(s_42sh));
    com_info *com_info = malloc(sizeof(struct command_info));
    h_info *history = malloc(sizeof(h_info));

    cpy_env(com_info, env);
    get_paths(com_info);
    get_buildins(com_info);
    com_info->return_value = 0;
    command(sh_42, com_info, history);
    free_all(history, com_info, sh_42, 1);
    return (0);
}
