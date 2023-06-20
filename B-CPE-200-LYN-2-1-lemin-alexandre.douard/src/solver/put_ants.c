/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** put_ants
*/

#include "lemin.h"
#include "my.h"

int cost_path(graph_t *graph)
{
    int i = graph->nb_paths - 1;

    for (i; i > 0; i--) {
        if (graph->ants / (i + 1) + graph->len_paths[i]
        < graph->ants / i + graph->len_paths[i - 1])
            break;
    }
    return i + 1;
}

char is_rooms_sorted(int *arr, int len)
{
    int min = arr[0];

    for (int i = 0; i < len; i++) {
        if (min > arr[i])
            return 0;
        min = arr[i];
    }
    return 1;
}

void sort_paths(graph_t *graph, room_t ***all_paths)
{
    int i = 0;
    int tmp_len = 0;
    room_t **tmp = NULL;
    while (is_rooms_sorted(graph->len_paths, graph->nb_paths) == 0) {
        if (graph->len_paths[i] > graph->len_paths[i + 1]) {
            tmp_len = graph->len_paths[i + 1];
            graph->len_paths[i + 1] = graph->len_paths[i];
            graph->len_paths[i] = tmp_len;
            tmp = all_paths[i + 1];
            all_paths[i + 1] = all_paths[i];
            all_paths[i] = tmp;
            i = 0;
        }
    }
}

int give_ants(graph_t *graph, room_t ***all_paths, int *ants, int step)
{
    int first = 1;
    for (int i = 0; i < graph->ants && i < step * graph->nb_paths; i++) {
        ants[i]++;
        if (ants[i] < graph->len_paths[i % graph->nb_paths]) {
            !first ? my_putchar(' ') : 0;
            first = 0;
            my_putchar('P');
            my_putstr(int_to_string(i + 1));
            my_putstr("-");
            my_putstr(all_paths[i % graph->nb_paths][ants[i]]->name);
        }
    }
    my_putchar('\n');
}

void put_ants(graph_t *graph, room_t ***all_path)
{
    int test = COL_ANT(graph->ants, graph->nb_paths);
    int step = 0;
    int nb_step = NB_ITER(graph->len_paths, graph->nb_paths, \
    COL_ANT(graph->ants, graph->nb_paths), graph->ants);
    int *ants = malloc(sizeof(ants[0]) * graph->ants);
    int done_ants = 0;
    graph->nb_paths = cost_path(graph);
    for (int i = 0; i < graph->ants; i++)
        ants[i] = 0;
    while (nb_step-- > 0) {
        step++;
        give_ants(graph, all_path, ants, step);
    }
}
