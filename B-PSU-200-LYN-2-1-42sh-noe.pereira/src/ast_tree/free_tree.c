/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** free_tree
*/
#include "ast_tree_functions.h"

void free_treee(ast_node *root)
{
    if (root == NULL)
        return;
    free_treee(root->f_g);
    free_treee(root->f_d);
    if (root->type == 10) {
        for (int i = 0; root->commands[i] != NULL; i++)
            free(root->commands[i]);
    }
    free(root);
}

//     free(sh_42->head->sons);
void free_tree(s_42sh *sh_42, com_info *com_info)
{
    for (int i = 0; i < sh_42->nb_com; i++) {
        free_treee(sh_42->head->sons[i]);
        free(sh_42->commands[i]);
    }
    free(sh_42->r_com);
    free(sh_42->commands);
    free(sh_42->head);
}
