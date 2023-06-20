/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** where_function
*/

#include "../../../include/sh42_include.h"
#include <unistd.h>

void where_function(ast_node *root, com_info *com_info)
{
    char *str;

    for (int i = 0; com_info->paths[i]; i++) {
        str = malloc(sizeof(char) * 500);
        str = strcpy(str, com_info->paths[i]);
        strcat(str, root->commands[1]);
        if (access(str, X_OK) == 0) {
            write(1, str, strlen(str));
            write(1, "\n", 1);
        }
        free(str);
    }
    for (int i = 0; com_info->built_in[i]; i++) {
        if (strcmp(com_info->built_in[i], root->commands[1]) == 0) {
            write(1, root->commands[1],
                strlen(root->commands[1]));
            write(1, " is a shell built-in\n", 21);
            break;
        }
    }
}
