/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** bfs
*/

#include "lemin.h"
#include "my.h"
#include <stdlib.h>

char dfs_recursive(room_t *room, room_t **result, int index, room_t *end)
{
    room->visited = true;
    result[index] = room;
    index++;
    result[index] = NULL;
    if (room == end)
        return 1;
    for (int i = 0; i < room->links_num; i++) {
        if (!room->links[i]->visited && !room->links[i]->used
        && dfs_recursive(room->links[i], result, index, end)) {
            return 1;
        }
        result[index] = NULL;
    }
    return 0;
}

room_t **dfs(graph_t *graph)
{
    room_t **result = (room_t **)malloc((graph->rooms_num + 1)
    * sizeof(room_t *));
    int index = 0;

    for (int i = 0; i < graph->rooms_num; i++) {
        if (graph->rooms[i])
            graph->rooms[i]->visited = false;
    }
    char a = dfs_recursive(graph->start, result, index, graph->end);
    return result;
}

char is_available_path(room_t **rooms)
{
    int tmp = 0;
    for (int i = 0; rooms[i]; i++) {
        if (rooms[i]->state == START) {
            tmp += 1;
            break;
        }
    }
    if (tmp == 0)
        return 0;
    for (int i = 0; rooms[i]; i++) {
        if (rooms[i]->state == END)
            return 1;
    }
    return 0;
}

int max_flow(graph_t *graph)
{
    room_t **path = dfs(graph);
    room_t ***all_path = malloc(sizeof(room_t **) * (MAX_PATH + 1));
    int i = 0;
    while (is_available_path(path) && i < MAX_PATH) {
        all_path[i++] = path;
        clear_path(graph, path);
        path = dfs(graph);
    }
    all_path[i] = NULL;
    graph->nb_paths = TAB_SIZE(all_path);
    graph->len_paths = malloc(sizeof(int) * (i + 1));
    for (int j = 0; j < i; j++) {
        graph->len_paths[j] = TAB_SIZE(all_path[j]);
    }
    if (graph->nb_paths == 0)
        return 1;
    put_ants(graph, all_path);
    return 0;
}
