/*
** EPITECH PROJECT, 2022
** my_putstr_n
** File description:
** put a string
*/

#include <unistd.h>

void my_putstr_n(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}
