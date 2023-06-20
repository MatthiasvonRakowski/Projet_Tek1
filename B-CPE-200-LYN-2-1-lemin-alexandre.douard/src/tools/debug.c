/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** debug
*/

#include "lemin.h"
#include "my.h"

void put_all_path(graph_t *graph, room_t ***all_path)
{
    for (int i = 0; i < graph->nb_paths; i++) {
        my_putstr("PATH N -> ");
        my_putstr(int_to_string(i));
        my_putchar('\n');
        for (int j = 0; j < graph->len_paths[i]; j++) {
            my_putstr(all_path[i][j]->name);
            my_putchar('\n');
        }
        my_putchar('\n');
    }
}

void put_all_room(room_t **room)
{
    my_putstr("put all room\n");
    for (int i = 0; room[i]; i++) {
        my_putstr("ROOM -> ");
        my_putstr(room[i]->name);
    }
}
