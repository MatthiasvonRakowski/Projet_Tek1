/*
** EPITECH PROJECT, 2022
** my_atoi
** File description:
** a short file description
*/

#include "../include/my.h"

int my_atoi(char *nb)
{
    if (!str_is_number(nb))
        return -1;
    int result = 0;
    int i = 0;
    while (nb[i] != '\0') {
        result *= 10;
        result += nb[i] - 48;
        i++;
    }
    return result;
}
