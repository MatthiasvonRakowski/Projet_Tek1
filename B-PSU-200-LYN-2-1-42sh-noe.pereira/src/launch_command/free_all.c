/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** free_all
*/
#include "../../include/sh42_include.h"

void free_all(h_info *h, com_info *com, s_42sh *sh, int n)
{
    free_h(h);
    for (int i = 0; i < com->nb_paths; i++)
        free(com->paths[i]);
    for (int i = 0; i < com->size_env; i++)
        free(com->envi[i]);
    free(com->com_line);
    free(com->cur_path);
    free(com->oldpath);
    if (n == 0)
        free_tree(sh, com);
}
