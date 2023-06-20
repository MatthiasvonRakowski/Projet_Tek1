/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** puts_endlines
*/

#include "my.h"
#include "lemin.h"
#include "parsing.h"

void puts_start_rooms(graph_t *graph, parsing_t *parse)
{
    my_putstr("##start\n");
    my_putstr(graph->start->name);
    my_putchar(' ');
    my_putstr(int_to_string(graph->start->cdt.x));
    my_putchar(' ');
    my_putstr(int_to_string(graph->start->cdt.y));
    my_putchar('\n');
}

void puts_end_rooms(graph_t *graph, parsing_t *parse)
{
    my_putstr("##end\n");
    my_putstr(graph->end->name);
    my_putchar(' ');
    my_putstr(int_to_string(graph->end->cdt.x));
    my_putchar(' ');
    my_putstr(int_to_string(graph->end->cdt.y));
    my_putchar('\n');
}
