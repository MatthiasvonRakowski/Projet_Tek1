/*
** EPITECH PROJECT, 2023
** valid_code
** File description:
** you're a bad developer
*/

#include "../include/my.h"

int valid_code(char *code)
{
    if (my_strlen(code) != 3) {
        my_printf("wrong position\n");
        return 0;
    }
    if ((code[0] < 'A' || code[0] > 'H') || (code[1] < '1' || code[1] > '8')) {
        my_printf("wrong position\n");
        return 0;
    }
    return 1;
}
