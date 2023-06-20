/*
** EPITECH PROJECT, 2022
** Pool-Day8
** File description:
** my_show_word_array
*/

#include <stddef.h>
#include "my.h"

int my_show_word_array(char *const *tab)
{
    int len;
    for (len = 0; tab[len] != NULL; len++);
    for (int i = 0; i < len; i++) {
        my_putstr(tab[i]);
        if (i <= len - 2)
            my_putstr("  ");
        else
            my_putchar('\n');
    }
    return 0;
}
