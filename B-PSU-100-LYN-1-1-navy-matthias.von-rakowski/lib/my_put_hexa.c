/*
** EPITECH PROJECT, 2022
** my_put_hexa
** File description:
** a short file description
*/

#include <stdio.h>
#include "include/my.h"
#include <stdlib.h>

char display_letter_hexa_maj(int nb)
{
    if (nb == 10)
        return 'A';
    if (nb == 11)
        return 'B';
    if (nb == 12)
        return 'C';
    if (nb == 13)
        return 'D';
    if (nb == 14)
        return 'E';
    if (nb == 15)
        return 'F';
}

char display_letter_hexa_min(int nb)
{
    if (nb == 10)
        return 'a';
    if (nb == 11)
        return 'b';
    if (nb == 12)
        return 'c';
    if (nb == 13)
        return 'd';
    if (nb == 14)
        return 'e';
    if (nb == 15)
        return 'f';
}

char display_letter_hexa(int nb, char type)
{
    if (type == 'X')
        return display_letter_hexa_maj(nb);
    else
        return display_letter_hexa_min(nb);
}

void print_hexa(char print, int nb, char *str)
{
    my_evil_str(str);
    if (print == 'y')
        my_reputstr(str);
}

int my_put_hexa(char print, int nb, char type)
{
    int save = nb;
    int count = 0;
    char *str = malloc(sizeof(char*) * size_int(nb));
    while (save >= 16) {
        if (save % 16 > 9)
            str[count] = display_letter_hexa(save % 16, type);
        else
            str[count] = save % 16 + 48;
        save /= 16;
        count++;
    }
    if (save > 9)
        str[count] = display_letter_hexa(save, type);
    else
        str[count] = save + 48;
    print_hexa(print, nb, str);
    int len = my_strlen(str);
    free(str);
    return len;
}
