/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int my_reputstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

int my_reputnstr(char const *str, char *precision)
{
    if (precision == NULL)
        return my_reputstr(str);
    int n = convert_number(precision);
    int i = 0;
    while ((str[i] != '\0') && (i < n)) {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
