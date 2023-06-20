/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** parser
*/

#include "my.h"
#include "lemin.h"
#include "parsing.h"

char skip_comment(char **p_str)
{
    char *str = *(p_str);

    for (; str[0] && str[0] != '\n'; str++);
    p_str = &str;
    return 0;
}

char parse_room(char **arr, graph_t *graph, parsing_t *parse)
{
    room_t *room = create_room(arr[0],
    VEC(my_getnbr(arr[1]), my_getnbr(arr[2])));
    if (parse->pos == P_START) {
        if (graph->start != NULL) {
            parse->is_error = 1;
            return 0;
        }
        room->state = START;
        graph->start = room;
    }  if (parse->pos == P_END) {
        if (graph->end != NULL) {
            parse->is_error = 1;
            return 0;
        }
        room->state = END;
        graph->end = room;
    }
    (parse->pos == P_NONE) ? room->state = NONE : 0;
    (verif_room_parse(graph, parse, room)) ? add_room(parse, graph, room) : 0;
    return 1;
}

char parse_links(char *buf, graph_t *graph, parsing_t *parse)
{
    char **links = split_links(buf);
    room_t *room_a = NULL;
    room_t *room_b = NULL;
    if (TAB_SIZE(links) != 2) {
        parse->is_error = 1;
        return 1;
    }
    add_buf_links(graph, buf);
    room_a = get_room_by_name(graph, links[0]);
    room_b = get_room_by_name(graph, links[1]);
    if (room_a == NULL || room_b == NULL) {
        parse->is_error = 1;
        return 1;
    } if (room_a == room_b
    || is_room_in_rooms(room_a->links, room_b, room_a->links_num)
    || is_room_in_rooms(room_b->links, room_a , room_b->links_num))
        return 0;
    add_links(parse, graph, room_a, room_b);
    add_links(parse, graph, room_b, room_a);
    return 0;
}

char parse_part(char *buf, char **arr, graph_t *graph, parsing_t *parse)
{
    if (parse->is_error)
        return 1;
    if (parse->part == ANTS) {
        graph->ants = my_getnbr(buf);
        parse->part = ROOMS;
        return 0;
    } if (parse->part == ROOMS) {
        if (my_strcmp("##end", buf) == 0) {
            parse->pos = P_END;
            return 0;
        } if (my_strcmp("##start", buf) == 0) {
            parse->pos = P_START;
            return 0;
        }
        parse_room(arr, graph, parse);
        parse->pos = P_NONE;
    }
    if (parse->part == LINKS)
        parse_links(buf, graph, parse);
}
