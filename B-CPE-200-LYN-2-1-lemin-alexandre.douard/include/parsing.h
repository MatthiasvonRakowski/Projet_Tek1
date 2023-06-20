/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** parsing
*/

#pragma once

    #include "lemin.h"

    typedef struct stack_line_s stack_line_t;

    struct stack_line_s {
        char *line;
        struct stack_line_s *next;
    };

    #define TAB_SIZE(tab) ({int _i = 0; for (; tab[_i]; _i++){_i += 0;} _i;})
    #define ROOM_LINE_SIZE 3
    #define TOK_LL(l) (!my_strtok(l, "#") && my_strtok(l, "-") ? true : false)
    #define IS_LINK_LINE(l) (TOK_LL(l[0]) && TAB_SIZE(l) == 1 ? true : false)
    #define VEC(x, y) (vector_t) {\
        x, y\
        }
    #define RLINE(str) my_putstr(str); my_putstr("\n")
    #define WA(arg) my_str_to_word_array(arg)

    enum node_position{
        P_NONE,
        P_START,
        P_END
    };

    enum part_parsing {
        ANTS,
        ROOMS,
        LINKS
    };

    typedef struct parsing {
        enum node_position pos;
        enum part_parsing part;
        char is_error;
        int nb_rooms;
        char **links;
        room_t *strat;
        room_t *end;
        room_t **rooms;
    } parsing_t;

    char ***get_map(graph_t *graph);
    room_t *create_room(char *name, vector_t cdt);
    room_t **create_graph(char ***map, graph_t *gr);
    bool my_strtok(char const *str, char const *tf);
    char **wstr_to_array(char const *str, char c);
    void create_links(room_t **graph, char **links);
    graph_t *parse(void);
    void display_rooms(room_t **rooms);
    room_t *get_room(room_t **rooms, char const *name);
    void create_nb_links(graph_t *graph);
    parsing_t *create_parsing(void);
    graph_t *create_a_graph(void);
    char is_num(char *str);
    char verif_part(char **arr, char *buf, graph_t *graph, parsing_t *parse);
    void add_room(parsing_t *parse, graph_t *graph, room_t *room);
    char parse_part(char *buf, char **arr, graph_t *graph, parsing_t *parse);
    char verif_room_parse(graph_t *graph, parsing_t *parse, room_t *room);
    char **split_links(char *src);
    void puts_graph(graph_t *graph, parsing_t *parse);
    void add_links(parsing_t *parse, graph_t *graph,
    room_t *room, room_t *link);
    void add_buf_links(graph_t *graph, char *buf);
    void puts_end_rooms(graph_t *graph, parsing_t *parse);
    void puts_start_rooms(graph_t *graph, parsing_t *parse);
    char is_room_in_rooms(room_t **rooms, room_t *room, int len);
