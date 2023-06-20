/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** wstr_to_array
*/

#include "my.h"
#include <stdlib.h>

int cline_size(char const *str, char c)
{
    int ret = 0;

    while (str[ret] && str[ret] != c)
        ret++;
    return ret;
}

int csize(char const *str, char c)
{
    int ret = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            ret++;
    }
    return ret;
}

char **wstr_to_array(char const *str, char c)
{
    char **ret = NULL;
    int line_size = cline_size(str, c);
    int size = csize(str, c);
    int index = 0;

    if (!(ret = malloc(sizeof(char *) * size + 1)))
        return NULL;
    for (int i = 0; i < size; i++, index++) {
        ret[i] = malloc(sizeof(char) * line_size);
        for (int j = 0; j < line_size; j++, index++)
            ret[i][j] = str[index];
    }
    ret[size] = NULL;
    return ret;
}
