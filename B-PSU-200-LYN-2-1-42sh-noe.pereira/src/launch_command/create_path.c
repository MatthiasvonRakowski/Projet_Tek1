/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** create_path
*/
#include "../../include/sh42_include.h"

void create_path(com_info *com)
{
    com->paths = malloc(sizeof(char *) * 4);
    com->paths[0] = "/usr/local/bin/";
    com->paths[1] = "/usr/bsd/";
    com->paths[2] = "/bin/";
    com->paths[3] = "/usr/bin/";
    com->nb_paths = 4;
}
