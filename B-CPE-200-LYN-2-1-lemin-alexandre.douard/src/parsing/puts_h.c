/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** puts_h
*/

#include "my.h"
#include "lemin.h"
#include "parsing.h"

void puts_none_rooms(graph_t *graph, parsing_t *parse)
{
    if (graph->rooms == NULL)
        return;
    for (int i = 0; graph->rooms[i]; i++) {
        if (graph->rooms[i]->state == NONE) {
            my_putstr(graph->rooms[i]->name);
            my_putchar(' ');
            my_putstr(int_to_string(graph->rooms[i]->cdt.x));
            my_putchar(' ');
            my_putstr(int_to_string(graph->rooms[i]->cdt.y));
            my_putchar('\n');
        }
    }
}

void puts_rooms(graph_t *graph, parsing_t *parse)
{
    my_putstr("#rooms\n");
    if (graph->start != NULL) {
        puts_start_rooms(graph, parse);
    }
    if (graph->end != NULL) {
        puts_end_rooms(graph, parse);
    }
    puts_none_rooms(graph, parse);
}

void puts_links(graph_t *graph, parsing_t *parse)
{
    my_putstr("#tunnels\n");
    if (graph->config_tmp == NULL) {
        my_putstr("#moves\n");
        parse->is_error = 1;
        return;
    }
    for (int i = 0; i < graph->config_tmp_len; i++) {
        my_putstr(graph->config_tmp[i]);
        my_putchar('\n');
    }
}

void puts_graph(graph_t *graph, parsing_t *parse)
{
    my_putstr("#number_of_ants\n");
    if (parse->part == ANTS) {
        parse->is_error = 1;
        return;
    }
    my_putstr(int_to_string(graph->ants));
    my_putchar('\n');
    if (parse->part == ROOMS || parse->part == LINKS) {
        puts_rooms(graph, parse);
    }
    if (parse->part == LINKS) {
        puts_links(graph, parse);
    } else {
        parse->is_error = 1;
    }
    if (parse->is_error == 0) {
        my_putstr("#moves\n");
    }
}
