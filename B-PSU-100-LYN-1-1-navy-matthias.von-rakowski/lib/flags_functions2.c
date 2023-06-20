/*
** EPITECH PROJECT, 2022
** convert_number
** File description:
** a short file description
*/

#include "include/my.h"
#include <stdio.h>

int get_hexa_len(int nb, char *flag)
{
    int len = 0;
    if (find_f(flag, '#'))
        len = len + 2;
    len += my_put_hexa('n', nb, ' ');
    return len;
}

int convert_number(char *str_nb)
{
    if (my_strlen(str_nb) == 1)
        return str_nb[0] - 48;
    int i = 1;
    while ((*str_nb) == 48)
        str_nb++;
    if (str_nb[0] == '\0')
        return 0;
    int nb = str_nb[0] - 48;
    while (str_nb[i] != '\0') {
        nb *= 10;
        nb += str_nb[i] - 48;
        i++;
    }
    return nb;
}
