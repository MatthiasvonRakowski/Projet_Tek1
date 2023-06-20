/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main
*/

#include "antman.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        write(1, &str[i], 1);
}

int main(int ac, char *av[])
{
    if (ac != 3) {
        my_putstr("You don't have enough argument.\n");
        return 84;
    }
    switch (av[2][0]) {
        case '1': case '2': case '3': break;
        default:
            my_putstr("Third argument must be a number between 1 and 3.\n");
            return 84;
    }
    if (antman(av[1]) == 84)
        return 84;
    return 0;
}
