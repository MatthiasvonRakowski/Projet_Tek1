/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** graph_h
*/

#include "lemin.h"

graph_t *create_a_graph(void)
{
    graph_t *graph = malloc(sizeof(graph_t));

    graph->ants = 0;
    graph->ants_left = 0;
    graph->end = NULL;
    graph->start = NULL;
    graph->rooms = NULL;
    graph->len_paths = NULL;
    graph->nb_paths = 0;
    graph->rooms_num = 0;
    graph->config_tmp_len = 0;
    graph->config_tmp = NULL;
    return graph;
}
