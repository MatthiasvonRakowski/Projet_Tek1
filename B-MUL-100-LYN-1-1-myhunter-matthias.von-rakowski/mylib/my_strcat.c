/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concentrate two strings in one
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    char *str = malloc(sizeof(char) * (my_strlen(src) + i + 1));
    int k = 0;

    for (; k < i; k++)
        str[k] = dest[k];
    for (k = 0; src[k] != '\0'; k++)
        str[i + k] = src[k];
    str[i + k] = '\0';
    return str;
}
