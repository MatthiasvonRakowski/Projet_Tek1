/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/c_graphical_prog/mylib/my_addnode
** File description:
** add a node
*/

#include "../include/my.h"

void *my_add_node_end(dino_t *list, void *element, void *(*init)(void *))
{
    void *temp = list;

    if (!list)
        return (*init)(element);
    while (list->next)
        list = list->next;
    list->next = (*init)(element);
    return temp;
}
