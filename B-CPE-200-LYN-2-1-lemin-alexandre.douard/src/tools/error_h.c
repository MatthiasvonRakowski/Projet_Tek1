/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** error_h
*/

#include "lemin.h"
#include <stdlib.h>

bool is_valide_node(graph_t *graph)
{
    if (graph->end == NULL || graph->start == NULL)
        return 0;
    return 1;
}

bool is_mult_def(graph_t *graph)
{
    char is_start = 0;
    char is_end = 0;

    for (int i = 0; graph->rooms[i]; i++) {
        if (graph->rooms[i]->state == START)
            is_start += 1;
        if (graph->rooms[i]->state == END)
            is_end += 1;
        if (is_end > 1 || is_start > 1)
            return 1;
    }
    if (is_end != 1 && is_start != 1)
        return 1;
    return 0;
}

bool is_same_in_rooms(room_t **rooms, vector_t co, const char *name)
{
    for (int i = 0; rooms[i]; i++) {
        if ((rooms[i]->cdt.x == co.x && rooms[i]->cdt.y == co.y)
        || rooms[i]->name == name)
            return 1;
    }
    return 0;
}

bool is_error(graph_t *graph)
{
    if (!is_valide_node(graph) || is_mult_def(graph))
        return 1;
    for (int i = 0; graph->rooms[i] && graph->rooms[i + 1]; i++) {
        if (is_same_in_rooms(&(graph->rooms[i + 1]),
        graph->rooms[i]->cdt, graph->rooms[i]->name))
            return 1;
    }
    return 0;
}
