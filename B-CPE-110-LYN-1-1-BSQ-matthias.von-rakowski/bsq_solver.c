/*
** EPITECH PROJECT, 2022
** bsq_solver
** File description:
** bsq helper
*/

#include "mylib/include/my.h"

int point_or_nbr(short **nb_arr, char **arr, char c, coor_t *pos)
{
    if (c != '.' && c != 'o')
        return 84;
    arr[pos->x][pos->y] = c;
    if (c == '.') {
        if (pos->x == 0 || pos->y == 0)
            nb_arr[pos->x][pos->y] = 1;
        else
            smaller(nb_arr, pos);
    } else
        nb_arr[pos->x][pos->y] = 0;
    if (pos->nbr == 0 && nb_arr[pos->x][pos->y] == 1) {
        pos->nbr = 1;
        pos->mem_x = pos->x;
        pos->mem_y = pos->y;
    }
    return 0;
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != '\n'; i++);
    return i;
}

int my_getnbr(char *str, coor_t *pos)
{
    int count = 0;

    for (; str[pos->k] != '\n' && str[pos->k] != '\0'; pos->k++) {
        count *= 10;
        count += str[pos->k] - '0';
    }
    return count;
}
