/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** links
*/

#include "parsing.h"
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

static void add_link(room_t *room, room_t **graph, char *name)
{
    int i = 0;
    room_t *ptr = NULL;

    while (my_strcmp(name, graph[i]->name))
        i++;
    ptr = graph[i];
    i = 0;
    while (room->links[i])
        i++;
    room->links_num++;
    room->links[i] = ptr;
}

static void stack_room(room_t **graph, room_t *room, char ***links)
{
    for (int i = 0; links[i]; i++) {
        if (!my_strcmp(links[i][0], room->name))
            add_link(room, graph, links[i][1]);
        if (!my_strcmp(links[i][1], room->name))
            add_link(room, graph, links[i][0]);
    }
}

static char ***format(char **map)
{
    char ***ret = malloc(sizeof(char **) * (TAB_SIZE(map) + 1));
    char **tmp;
    int place;

    ret[TAB_SIZE(map)] = NULL;
    for (int i = 0; map[i]; i++) {
        place = 0;
        while (map[i][place] != '-')
            place++;
        map[i][place] = '\0';
        tmp = malloc(sizeof(char *) * 2);
        tmp[0] = map[i];
        tmp[1] = map[i] + place + 1;
        ret[i] = tmp;
    }
    return ret;
}

void create_links(room_t **graph, char **map_links)
{
    char ***links = format(map_links);

    for (int i = 0; graph[i]; i++)
        stack_room(graph, graph[i], links);
}

void create_nb_links(graph_t *graph)
{
    for (int i = 0; i < graph->rooms_num; i++) {
        graph->rooms[i]->links_num = 1;
    }
}
