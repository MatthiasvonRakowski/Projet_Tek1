/*
** EPITECH PROJECT, 2022
** Pool-Day8
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++) {
        str[i] = src[i];
    }
    str[len] = '\0';
    return str;
}
