/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int my_strnlen(char const *str, char *precision)
{
    if (precision == NULL)
        return my_strlen(str);
    int n = convert_number(precision);
    int i = 0;
    while ((str[i] != '\0') && (i < n))
        i++;
    return i;
}
