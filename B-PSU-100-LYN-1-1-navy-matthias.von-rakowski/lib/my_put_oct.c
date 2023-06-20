/*
** EPITECH PROJECT, 2022
** my_put_oct
** File description:
** a short file description
*/

#include <stdlib.h>
#include "include/my.h"

int size_int(int nb)
{
    int save = nb;
    int len = 0;
    if (save < 0) {
        save = -nb;
    }
    if (save < 10)
        return 1;
    while (save > 9) {
        save /= 10;
        len++;
    }
    return len + 1;
}

int my_put_oct(int nb)
{
    int save = nb;
    if (save < 0)
        save = -nb;
    char *str = malloc(sizeof(char*) * size_int(nb) + 2);
    int count = 0;
    while (save >= 9) {
        str[count] = save % 8 + 48;
        save /= 8;
        count++;
    }
    str[count] = save + 48;
    my_evil_str(str);
    my_reputstr(str);
    int len = my_strlen(str);
    free(str);
    return len;
}
