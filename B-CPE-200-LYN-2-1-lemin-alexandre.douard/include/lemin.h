/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** lemin
*/

#pragma once

    #include <stdbool.h>
    #include <limits.h>
    #include <stdlib.h>
    #define MAX_DIGITS 10
    #define TAB_SIZE(tab) ({int _i = 0; for (; tab[_i]; _i++){_i += 0;} _i;})
    #define MAX(a, b) ((a > b) ? a : b)
    #define MIN(a, b) ((a < b) ? a : b)
    #define IS_DIG(a) ((a >= '0' && a <= '9') ? 1 : 0)
    #define IS_LOW(a) ((a >= 'a' && a <= 'z') ? 1 : 0)
    #define IS_UP(a) ((a >= 'A' && a <= 'Z') ? 1 : 0)
    #define IS_ALNUM(a) ((IS_DIG(a) || IS_LOW(a) || IS_UP(a)) ? 1 : 0)
    #define IS_ROOM(a) ((IS_DIG(a) || \
    IS_LOW(a) || IS_UP(a) || a == '_') ? 1 : 0)
    #define MAX_PATH 100
    #define COL_ANT(n_ant, nb_path) ((n_ant - 1) % nb_path)
    #define NB_START(nb_ants, nb_path) \
    ((int) nb_ants / nb_path + ((nb_ants % nb_path) ? 1 : 0))
    #define NB_ITER(len_path, nb_path, col_last_ant, nb_ants) \
    (MAX(int_arr_max_ind(len_path, 0, col_last_ant + 1) - 2, \
    int_arr_max(len_path, nb_path) - 3) + NB_START(nb_ants, nb_path))
    #define is_sep(x) (str[i] == ' ' || str[i] == '\t')

    typedef struct room_s room_t;
    typedef struct vector_s vector_t;
    typedef struct graph_s  graph_t;

    struct vector_s {
        int x;
        int y;
    };

    struct room_s {
        bool visited;
        bool used;
        enum {
            NONE,
            START,
            END
        } state;
        char const *name;
        struct vector_s cdt;
        int links_num;
        struct room_s **links;
    };

    struct graph_s {
        int ants;
        int ants_left;
        int rooms_num;
        int nb_paths;
        int *len_paths;
        int config_tmp_len;
        char **config_tmp;
        room_t *start;
        room_t *end;
        room_t **rooms;
    };

    void lemin(void);
    int max_flow(graph_t *graph);
    bool is_error(graph_t *graph);
    void clear_path(graph_t *graph, room_t **rooms);
    void put_ants(graph_t *graph, room_t ***all_path);
    int int_arr_max(int *arr, int len);
    int int_arr_max_ind(int *arr, int start_ind, int end_ind);
    char *int_to_string(int num);
    void put_all_path(graph_t *graph, room_t ***all_path);
    graph_t *create_a_graph(void);
    char is_end_node(char *str);
    char is_comment(char *str);
    char *cleaning_str_parse(char **p_str);
    char is_start_node(char *str);
    void put_all_room(room_t **room);
    room_t *get_room_by_name(graph_t *graph, char *name);
    int int_arr_min(int *arr, int len);
