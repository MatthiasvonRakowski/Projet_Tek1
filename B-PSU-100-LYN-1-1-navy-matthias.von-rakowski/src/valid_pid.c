/*
** EPITECH PROJECT, 2023
** src/valid_expression
** File description:
** valid_pid
*/

#include "../include/my.h"

int valid_pid(char *pid)
{
    if (!str_is_number(pid))
        return 0;
    if (my_strcmp(pid, "0") == 1)
        return 0;
    return 1;
}
