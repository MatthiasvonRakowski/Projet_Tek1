/*
** EPITECH PROJECT, 2023
** 3_MyPaint_2
** File description:
** my_strcharcat
*/

#include "my.h"

char *my_strcharcat(char *dest, const char c)
{
    int dest_len = my_strlen(dest);

    dest[dest_len] = c;
    dest[dest_len + 1] = '\0';

    return dest;
}
