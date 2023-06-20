/*
** EPITECH PROJECT, 2022
** flagS
** File description:
** a short file description
*/

#include <stdio.h>
#include "include/my.h"

int my_char_is_printable(char c)
{
    if ((c < 32) || (c >= 127))
        return 0;
    return 1;
}

int display_non_printable(char c)
{
    int save = c;
    char str[4];
    int count = 0;
    while (save >= 8) {
        str[count] = save % 8 + 48;
        save /= 8;
        count++;
    }
    str[count] = save + 48;
    my_evil_str(str);
    for (int i = 0; i < 3 - my_strlen(str); i++)
        my_putchar('0');
    my_reputstr(str);
    return 4;
}

int flag_s(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (!my_char_is_printable(str[i])) {
            my_putchar('\\');
            count += display_non_printable(str[i]);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
            count++;
        }
    }
    return count;
}

void my_put_bin(int nb)
{
    if (nb < 0)
        return;
    if (nb == 0)
        my_put_nbr(0);
    if (nb > 0) {
        if (nb / 2 != 0)
            my_put_bin(nb / 2);
        my_put_nbr(nb % 2);
    }
}
