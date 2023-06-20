/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** example of bad code:
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    write(1, str, i);
}
