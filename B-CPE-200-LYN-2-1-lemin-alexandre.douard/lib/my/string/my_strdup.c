/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** duplicate with a new malloc a string
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return str;
}
