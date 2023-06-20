/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** main
*/

#include "lemin.h"
#include "my.h"
#include "parsing.h"
#include <stdio.h>

int main(void)
{
    graph_t *graph = parse();
    if (graph == NULL || graph->start == NULL || graph->end == NULL)
        return 84;
    if (max_flow(graph)) {
        return 84;
    }
    return 0;
}
