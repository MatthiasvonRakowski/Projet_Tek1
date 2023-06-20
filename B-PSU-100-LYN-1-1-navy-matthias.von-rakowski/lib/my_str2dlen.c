/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** a short file description
*/

#include "include/my.h"

int my_str2dlen(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}
