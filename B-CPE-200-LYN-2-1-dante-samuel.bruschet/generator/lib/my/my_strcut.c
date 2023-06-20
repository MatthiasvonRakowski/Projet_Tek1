/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** , if free_args = 0, no free, = 1 free
*/

#include <stdlib.h>

char *my_strcut(char *str, char ele, int free_args)
{
    int size = 0;
    int i = 0;
    char *n_str;

    for (; str[i] != '\0'; i++)
        if (str[i] == ele)
            size = i;
    if (size == 0 && i != 1)
        size = i;
    n_str = malloc(sizeof(char) * (size + 1));
    n_str[size] = '\0';
    for (i = 0; i != size; i++)
        n_str[i] = str[i];
    if (free_args == 1)
        free(str);
    return n_str;
}
