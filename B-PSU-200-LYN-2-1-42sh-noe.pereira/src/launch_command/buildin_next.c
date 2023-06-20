/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** buildin_next
*/

#include "../../include/sh42_include.h"

void buildin_next(ast_node *root, com_info *com_info, h_info *history,
s_42sh *sh)
{
    if (!strcmp(root->commands[0], "which"))
        com_info->which = 1;
    if (!strcmp(root->commands[0], "alias"))
        com_info->alias = 1;
    if (!strcmp(root->commands[0], "unalias"))
        com_info->unalias = 1;
}
