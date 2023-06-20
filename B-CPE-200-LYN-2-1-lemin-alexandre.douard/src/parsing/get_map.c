/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** get_map
*/

#include "parsing.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char *copy(char const *str)
{
    char *ret = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; str[i]; i++)
        ret[i] = str[i];
    return ret;
}

static stack_line_t *add_line(stack_line_t *head, char *line)
{
    stack_line_t *tmp;

    tmp = malloc(sizeof(stack_line_t));
    line[my_strlen(line) - 1] = '\0';
    tmp->line = copy(line);
    tmp->next = head;
    return tmp;
}

static char **get_lines(void)
{
    stack_line_t *head = NULL;
    stack_line_t *tmp = NULL;
    char *line = NULL;
    size_t linecap = 0;
    int size = 0;
    char **ret = NULL;

    for (; getline(&line, &linecap, stdin) > 0; size++)
        head = add_line(head, line);
    ret = malloc(sizeof(char *) * (size + 1));
    ret[size] = NULL;
    for (int i = size - 1; head; i--) {
        ret[i] = head->line;
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
    return ret;
}

char ***get_map(graph_t *graph)
{
    char **tmp = get_lines();
    int size = TAB_SIZE(tmp);
    char ***ret = malloc(sizeof(char **) * (size + 1));

    for (int i = 0; i < size; i++)
        ret[i] = my_str_to_word_array(tmp[i]);
    ret[size] = NULL;
    my_putstr(tmp[0]);
    graph->ants = my_getnbr(tmp[0]);
    my_putstr("\n#rooms\n");
    graph->config_tmp = tmp;
    return ret;
}
