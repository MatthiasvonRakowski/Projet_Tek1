/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** clear_path
*/

#include "lemin.h"
#include <stdlib.h>

void delete_node_graph(graph_t *graph, room_t *room)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < graph->rooms_num; i++) {
        if (graph->rooms[i] == room) {
            graph->rooms[i] = NULL;
            break;
        }
    }
    for (i = 0; i < graph->rooms_num; i++) {
        if (graph->rooms[i] == NULL)
            continue;
        for (j = 0; graph->rooms[i]->links_num < j; j++) {
            (graph->rooms[i]->links[j] == room)
            ? graph->rooms[i]->links[j] = NULL : 0;
        }
    }
}

void clear_path(graph_t *graph, room_t **rooms)
{
    int i = 0;
    int j = 0;

    for (; rooms[i] && rooms[i]->state != START; i++);
    for (; rooms[i] && rooms[i]->state != END; i++) {
        delete_node_graph(graph, rooms[i]);
    }
}
