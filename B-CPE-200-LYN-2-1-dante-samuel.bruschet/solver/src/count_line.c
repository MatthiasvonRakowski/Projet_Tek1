/*
** EPITECH PROJECT, 2023
** src/generator_manager
** File description:
** valid expression
*/

#include "../include/my.h"

int count_line(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}
