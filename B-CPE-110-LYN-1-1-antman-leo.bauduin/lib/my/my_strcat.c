/*
** EPITECH PROJECT, 2022
** Pool-Day7
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *str)
{
    int y = 0;
    int i = 0;
    char *result = malloc(sizeof(char) * 10000);

    for (y = 0; dest[y] != '\0'; i++, y++)
        result[i] = dest[y];
    for (y = 0; str[y] != '\0'; i++, y++) {
        result[i] = str[y];
    }
    result[i] = '\0';
    return result;
}
