/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** str_h
*/

#include "lemin.h"
#include "my.h"

char *cleaning_str_parse(char **p_str)
{
    char *str = *(p_str);
    char *dest = malloc(sizeof(char) * 500);
    char *res;
    int dest_idx = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '#')
            break;
        if (is_sep(str[i]) && !dest_idx)
            continue;
        if (is_sep(str[i])) {
            dest[dest_idx - 1] == ' ' ? 0 : (dest[dest_idx++] = ' ');
            continue;
        }
        dest[dest_idx++] = str[i];
    }
    dest[(dest[dest_idx - 1] == ' ') ? dest_idx - 1 : dest_idx] = 0;
    res = my_strdup(dest);
    free(dest);
    *(p_str) = res;
    return res;
}
