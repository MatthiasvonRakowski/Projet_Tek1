/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** repeat
*/

#include "../../include/struct_42sh.h"
#include "../launch_command/function_launch_command.h"

static bool valid_number(char *str)
{
    str = clean_str(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] < 48 || str[i] > 57) {
            return (false);
        }
    }
    return (true);
}

int repeat_function(ast_node *root, com_info *com_info,
h_info *history, s_42sh *sh)
{
    int k = 0;
    for (k = 0; root->commands[k] != NULL; k++);
    if (k < 2) {
        write(2, "repeat: Too few arguments.\n", 27);
        com_info->return_value = 1;
        return (1);
    }
    if (valid_number(root->commands[1]) == false) {
        write(2, "repeat: Badly formed number.\n", 29);
        com_info->return_value = 1;
        return (1);
    }
    int nb = atoi(root->commands[1]);
    for (int i = 0; root->commands[i + 1] != NULL; i++) {
        root->commands[i] = root->commands[i + 2];
    }
    for (int j = 0; j < nb; j++) {
        buildin(root, com_info, history, sh);
    }
    return (0);
}
