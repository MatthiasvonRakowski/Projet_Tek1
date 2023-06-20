/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** verif_h
*/

#include "lemin.h"
#include "my.h"
#include "parsing.h"

char verif_room_parse(graph_t *graph, parsing_t *parse, room_t *room)
{
    for (int i = 0; i < graph->rooms_num; i++) {
        if ((graph->rooms[i]->cdt.x == room->cdt.x
        && graph->rooms[i]->cdt.y == room->cdt.y)
        || my_strcmp(graph->rooms[i]->name, room->name) == 0) {
            parse->is_error = 1;
            return 0;
        }
    }
    return 1;
}
