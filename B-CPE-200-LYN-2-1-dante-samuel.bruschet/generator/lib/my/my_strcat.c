/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concentrate two strings in one, if free_args = 0, no free, 1 dest, 2 sec, all
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src, int free_args)
{
    int i = my_strlen(dest);
    char *str = malloc(sizeof(char) * (my_strlen(src) + i + 1));
    int k = 0;

    for (; k < i; k++)
        str[k] = dest[k];
    for (k = 0; src[k] != '\0'; k++)
        str[i + k] = src[k];
    str[i + k] = '\0';
    switch (free_args) {
        case 1: free(dest); break;
        case 2: free(src); break;
        case 3: free(dest);
            free(src);
            break;
        default: break;
    };
    return str;
}
