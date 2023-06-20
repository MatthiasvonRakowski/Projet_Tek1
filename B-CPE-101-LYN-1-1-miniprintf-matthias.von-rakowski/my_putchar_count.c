/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** Display a my_putchar
*/

#include<unistd.h>

int my_putchar_count (char c)
{
    write(1, &c, 1);
    if (c != '\0')
        return 1;
    return 0;
}
