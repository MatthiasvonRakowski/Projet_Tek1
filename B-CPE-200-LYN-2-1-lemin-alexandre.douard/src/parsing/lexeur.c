/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** lexeur
*/

#include "lemin.h"
#include "my.h"

char is_comment(char *str)
{
    if (str[0] != '#')
        return 0;
    if (my_strcmp(str, "##start") != 0 && my_strcmp(str, "##end") != 0)
        return 1;
    return 0;
}

char is_int(char *str)
{
    if (str[0] && str[0] == '-')
        str++;
    if (my_strlen(str) > 10)
        return 0;
    for (; str[0] && str[0] != '\n'; str++) {
        if (!IS_DIG(str[0]))
            return 0;
    }
    return 1;
}

char is_start_node(char *str)
{
    if (str[0] && str[0] == '#')
        if (my_strcmp(str, "##start\n") == 0)
            return 1;
    return 0;
}

char is_end_node(char *str)
{
    if (str[0] && str[0] == '#')
        if (my_strcmp(str, "##end\n") == 0)
            return 1;
    return 0;
}
