/*
** EPITECH PROJECT, 2022
** my_get_every_flag
** File description:
** a short file description
*/

#include "include/struct_formats.h"
#include <unistd.h>

char find_f(char *flag, char to_find)
{
    if (flag == NULL)
        return 0;
    int i = 0;
    while (flag[i] != '\0') {
        if (flag[i] == to_find)
            return 1;
        i++;
    }
    return 0;
}

char char_is_flag(char c)
{
    for (int i = 0; i < 5; i++) {
        if (LIST_FLAGS[i].specifier == c)
            return 1;
    }
    return 0;
}

char *my_get_flag(char *flags)
{
    int i = 0;
    if (!char_is_flag(flags[0]))
        return NULL;
    while (char_is_flag(flags[i])) {
        i++;
    }
    char *str = malloc(sizeof(char *) * (i + 1));
    my_strncpy(str, flags, i);
    return str;
}

char *my_get_width(char *flags)
{
    int i = 0;
    if (!char_is_number(flags[0]))
        return NULL;
    while (char_is_number(flags[i]))
        i++;
    char *str = malloc(sizeof(char *) * (i + 1));
    my_strncpy(str, flags, i);
    return str;
}

char *my_get_precision(char *flags)
{
    if (flags[0] != '.')
        return NULL;
    flags++;
    if ((flags[0] == '\0') || (!char_is_number(flags[0])))
        return NULL;
    int i = 0;
    while (char_is_number(flags[i]))
        i++;
    char *str = malloc(sizeof(char *) * i + 1);
    my_strncpy(str, flags, i);
    return str;
}
