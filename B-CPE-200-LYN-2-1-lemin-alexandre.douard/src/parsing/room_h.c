/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** room_h
*/

#include "lemin.h"
#include "parsing.h"
#include "my.h"

void add_room(parsing_t *parse, graph_t *graph, room_t *room)
{
    room_t **n_rooms = malloc(sizeof(room_t *) * (graph->rooms_num + 2));
    for (int i = 0; i < graph->rooms_num; i++) {
        n_rooms[i] = graph->rooms[i];
    }
    n_rooms[graph->rooms_num++] = room;
    n_rooms[graph->rooms_num] = NULL;
    free(graph->rooms);
    graph->rooms = n_rooms;
}

void add_buf_links(graph_t *graph, char *buf)
{
    char **n_buf = malloc(sizeof(char *) * (graph->config_tmp_len + 2));

    for (int i = 0; i < graph->config_tmp_len; i++) {
        n_buf[i] = graph->config_tmp[i];
    }
    n_buf[graph->config_tmp_len++] = buf;
    n_buf[graph->config_tmp_len] = NULL;
    free(graph->config_tmp);
    graph->config_tmp = n_buf;
}

void add_links(parsing_t *parse, graph_t *graph, room_t *room, room_t *link)
{
    room_t **n_rooms = malloc(sizeof(room_t *) * (room->links_num + 2));

    if (link == room)
        return;
    for (int i = 0; i < room->links_num; i++) {
        n_rooms[i] = room->links[i];
    }
    n_rooms[room->links_num++] = link;
    n_rooms[room->links_num] = NULL;
    free(room->links);
    room->links = n_rooms;
}

char is_room_in_rooms(room_t **rooms, room_t *room, int len)
{
    for (int i = 0; i < len; i++) {
        if (rooms[i] == room)
            return 1;
    }
    return 0;
}
