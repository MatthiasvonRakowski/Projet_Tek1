/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** parse
*/

#include "parsing.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void rep_act(graph_t *graph, parsing_t *parse, char *buf)
{
    char **arr = NULL;
    if (is_comment(buf))
        return;
    if (my_strcmp(buf, "##start") != 0 && my_strcmp(buf, "##end") != 0)
        cleaning_str_parse(&buf);
    arr = my_str_to_word_array(buf);
    if (!verif_part(arr, buf, graph, parse)) {
        parse->is_error = 1;
        return;
    }
    parse_part(buf, arr, graph, parse);
}

char *getline_null_term(char **p_buf, int len)
{
    char *buf = *(p_buf);
    char *n_str = malloc(sizeof(char) * (len + 1));

    my_strncpy(n_str, buf, len);
    if (buf[len - 1] == '\n')
        n_str[len - 1] = 0;
    else {
        n_str[len] = 0;
    }
    free(buf);
    *p_buf = n_str;
    return n_str;
}

graph_t *parse(void)
{
    size_t i = 0;
    int len = 0;
    char *buf = NULL;
    char *trmp = NULL;
    graph_t *graph = create_a_graph();
    parsing_t *parse = create_parsing();

    while ((len = getline(&buf, &i, stdin)) != -1 && parse->is_error == 0) {
        trmp = my_strdup(buf);
        trmp = getline_null_term(&trmp, len);
        rep_act(graph, parse, trmp);
    }
    puts_graph(graph, parse);
    return (parse->is_error) ? NULL : graph;
}
