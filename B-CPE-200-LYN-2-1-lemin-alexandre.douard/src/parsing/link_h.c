/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** link_h
*/

#include "my.h"
#include "lemin.h"
#include "parsing.h"

room_t *get_room_by_name(graph_t *graph, char *name)
{
    for (int i = 0; i < graph->rooms_num; i++) {
        if (my_strcmp(graph->rooms[i]->name, name) == 0)
            return graph->rooms[i];
    }
    return NULL;
}

static int count_words(char const *str)
{
    int word_count = str[0] != '\0' ? 1 : 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            word_count++;
    }
    return word_count;
}

static void insert_links(char **tab, int word_count, int word_size, char *str)
{
    tab[word_count] = malloc(sizeof(char) * (word_size + 1));
    my_strncpy(tab[word_count], str, word_size);
}

char **split_links(char *src)
{
    char *str = my_strdup(src);
    my_clean_str(str);
    int tab_len = count_words(str);
    char **tab = malloc(sizeof(char *) * (tab_len + 1));
    int word_count = 0;
    int word_size = 0;
    int i = 0;

    for (; str[i] != '\0'; i++, word_size++) {
        if (str[i] == '-') {
            insert_links(tab, word_count, word_size, str + i - word_size);
            word_count++;
            word_size = 0;
            i++;
        }
    }
    insert_links(tab, word_count, word_size, str + i - word_size);
    tab[tab_len] = NULL;
    free(str);
    return tab;
}
