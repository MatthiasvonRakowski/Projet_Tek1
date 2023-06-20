/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** a short file description
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
