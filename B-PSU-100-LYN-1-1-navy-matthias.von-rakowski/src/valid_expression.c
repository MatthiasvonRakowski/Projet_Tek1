/*
** EPITECH PROJECT, 2023
** src/valid_expression
** File description:
** valid_expression
*/

#include "../include/my.h"

int valid_expression(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return 0;
    if (ac == 2)
        return valid_script(av[1]);
    if (!valid_pid(av[1]))
        return 0;
    return valid_script(av[2]);
}
