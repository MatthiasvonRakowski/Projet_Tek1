/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Allow place in the memory
*/

#include <stdlib.h>

int my_strlen_rec(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    int size = my_strlen_rec(src);
    char *str = malloc(sizeof(char) * (size + 1));

    my_strcpy(str, src);
    return str;
}
