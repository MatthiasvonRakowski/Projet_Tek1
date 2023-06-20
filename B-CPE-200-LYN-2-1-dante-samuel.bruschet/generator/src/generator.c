/*
** EPITECH PROJECT, 2023
** src/generator
** File description:
** generator maker
*/

#include "generator.h"
#include <stdlib.h>
#include <ctype.h>

int str_is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return 0;
    return 1;
}

int info(void)
{
    printf("USAGE:\n\t./generator x y [perfect]\n\tx: intenger\n\t");
    printf("y: intenger\n\t[perfect]: default is imperfect, ");
    printf("write perfect if needed\n");
}

int main(int ac, char **av)
{
    int x;
    int y;

    if (!(ac == 4 || ac == 3 || ac == 2))
        return 84;
    if (ac == 2 && !strcmp("-h", av[1]))
            return info();
    if (ac == 2)
            return 84;
    if (!str_is_num(av[1]) || !str_is_num(av[2]))
        return 84;
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x < 1 || y < 1)
        return 84;
    if (ac == 3)
        return generator_imperfect(x, y);
    if (ac == 4 && !strcmp("perfect", av[3]))
        return generator_perfect(x, y);
    return 84;
}
