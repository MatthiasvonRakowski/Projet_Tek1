/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** graph
*/

#include "parsing.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

static char **get_links_lines(char ***map)
{
    char **ret;
    int links = 0;
    int index = 0;

    for (int i = 0; map[i]; i++) {
        if (IS_LINK_LINE(map[i]))
            links++;
    }
    ret = malloc(sizeof(char *) * (links + 1));
    ret[links] = NULL;
    for (int i = 0; map[i]; i++) {
        if (IS_LINK_LINE(map[i]))
            ret[index++] = map[i][0];
    }
    return ret;
}

static char ***get_rooms_lines(char ***map)
{
    char ***ret;
    int rooms = 0;
    int index = 0;

    for (int i = 0; map[i]; i++) {
        if (TAB_SIZE(map[i]) >= ROOM_LINE_SIZE && !my_strtok(map[i][0], "#"))
            rooms++;
    }
    ret = malloc(sizeof(char **) * (rooms + 1));
    ret[rooms] = NULL;
    for (int i = 0; map[i]; i++) {
        if (TAB_SIZE(map[i]) >= ROOM_LINE_SIZE && !my_strtok(map[i][0], "#"))
            ret[index++] = map[i];
    }
    return ret;
}

static int get_lks(char *name, char **links)
{
    int ret = 0;

    for (int i = 0; links[i]; i++) {
        if (my_strtok(links[i], name))
            ret++;
    }
    return ret;
}

static void stack_room_array(room_t **rooms, char ***m_r, char **l, char **tmp)
{

    display_rooms(rooms);
}

room_t **create_graph(char ***map, graph_t *gr)
{
    char **links_lines = get_links_lines(map);
    char ***rooms_lines = get_rooms_lines(map);
    room_t **graph = malloc(sizeof(room_t *) * (TAB_SIZE(rooms_lines) + 1));

    graph[TAB_SIZE(rooms_lines)] = NULL;
    stack_room_array(graph, rooms_lines, links_lines, gr->config_tmp);
    my_putstr("#tunnels\n");
    for (int i = 0; links_lines[i]; i++) {
        my_putstr(links_lines[i]);
        my_putstr("\n");
    }
    create_links(graph, links_lines);
    return graph;
}
