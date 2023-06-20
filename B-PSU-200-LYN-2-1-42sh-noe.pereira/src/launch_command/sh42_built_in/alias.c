/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** alias
*/

#include "../../../include/sh42_include.h"

void alias_list(alias_t *alias)
{
    for (int i = 0; alias; alias = alias->next, i++)
        printf("alias %s\t%s\n", alias->alias, alias->command);
}

alias_t *take_ele(alias_t *new, ast_node *node)
{
    int i = 0;
    int j = 2;

    for (; node->commands[1][i]; i++)
        if (node->commands[1][i] == '=')
            break;
    new->alias = strndup(node->commands[1], i);
    (i != (int) strlen(node->commands[1])) ? (j = 1) : (i = -1);
    i++;
    if (node->commands[j][i] == '\'' || node->commands[j][i] == '"')
        new->command = strndup(&node->commands[j][i + 1],
            strlen(&node->commands[j][i + 1]) - 1);
    else
        new->command = strndup(&node->commands[j][i],
            strlen(&node->commands[j][i]));
    return new;
}

alias_t *create_alias(alias_t *list, ast_node *node)
{
    alias_t *new = malloc(sizeof(alias_t));

    new = take_ele(new, node);
    new->next = list;
    return new;
}

// choose the good function to execute
void alias_function(ast_node *root, com_info *com_info)
{
    alias_t *temp = com_info->alias_list;

    if (root->commands[1] == NULL) {
        alias_list(com_info->alias_list);
        return;
    }
    while (temp) {
        if (strcmp(temp->alias, root->commands[1]) == 0) {
            free(temp->command);
            free(temp->alias);
            temp = take_ele(temp, root);
            return;
        }
        temp = temp->next;
    }
    com_info->alias_list = create_alias(com_info->alias_list, root);
}

void unalias_function(ast_node *root, com_info *com_info)
{
    alias_t *temp = com_info->alias_list;
    alias_t *prev = NULL;

    if (root->commands[1] == NULL) {
        write(2, "unalias: Too few arguments.\n", 28);
        return;
    }
    for (; temp; temp = temp->next) {
        if (strcmp(temp->alias, root->commands[1]) == 0) {
            (prev == NULL) ? (com_info->alias_list = temp->next) :
                (prev->next = temp->next);
            free(temp->alias);
            free(temp->command);
            free(temp);
            return;
        }
        prev = temp;
    }
}
