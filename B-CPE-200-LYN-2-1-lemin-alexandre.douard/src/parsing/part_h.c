/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** part_h
*/

#include "lemin.h"
#include "parsing.h"
#include "my.h"

char verif_ants(char *str)
{
    if (!is_num(str)) {
        return 0;
    }
    if (my_getnbr(str) <= 0)
        return 0;
    return 1;
}

char verif_room(char **arr)
{
    if (TAB_SIZE(arr) == 1 && (my_strcmp("##end", arr[0]) == 0
    || my_strcmp("##start", arr[0]) == 0)) {
        return 1;
    }
    if (TAB_SIZE(arr) != 3)
        return 0;
    for (int i = 0; arr[0][i]; i++) {
        if (!IS_ROOM(arr[0][i]))
            return 0;
    }
    if (!is_num(arr[1]) || !is_num(arr[2]))
        return 0;
    return 1;
}

char verif_link(char *buf)
{
    int i = 0;
    if (buf == NULL || buf[0] == 0 || buf[0] == '-')
        return 0;
    for (i; buf[i] && buf[i] != '-'; i++);
    if (buf[i] == 0)
        return 0;
    return 1;
}

char verif_part(char **arr, char *buf, graph_t *graph, parsing_t *parse)
{
    if (parse->part == ANTS && verif_ants(buf))
        return 1;
    if (parse->part == ANTS)
        return 0;
    if (parse->part == ROOMS && verif_room(arr))
        return 1;
    if (parse->part == ROOMS) {
        parse->part = LINKS;
    }
    if (verif_link(buf))
        return 1;
    parse->is_error = 1;
    return 0;
}
