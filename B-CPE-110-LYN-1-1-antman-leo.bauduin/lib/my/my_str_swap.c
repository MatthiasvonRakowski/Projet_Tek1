/*
** EPITECH PROJECT, 2022
** Pool-Day10
** File description:
** my_str_swap
*/

#include <stdlib.h>

char *my_strdup(char const *src);
int my_strlen(char const *str);

void my_str_swap(char *a, char *b)
{
    char *reverse = my_strdup(a);

    a = malloc(sizeof(char) * (my_strlen(b) + 1));
    a = b;
    b = malloc(sizeof(char) * (my_strlen(reverse) + 1));
    b = reverse;
}
