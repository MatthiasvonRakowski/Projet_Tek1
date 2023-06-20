/*
** EPITECH PROJECT, 2022
** init
** File description:
** initialisate the structur
*/

#include "mylib/include/my.h"

int create_conding_style(char *str, short **nb_arr, char **arr, coor_t *pos)
{
    for (pos->y = 0; pos->y < pos->size; pos->y++, pos->k++) {
        if (str[pos->k % pos->t_size] != '.' &&
            str[pos->k % pos->t_size] != 'o')
            return 84;
        pos->k %= pos->t_size;
        point_or_nbr(nb_arr, arr, str[pos->k], pos);
    }
    return 0;
}

void reinit(char **arr, coor_t *pos)
{
    arr[pos->x][pos->y] = '\n';
    arr[pos->x][pos->y + 1] = '\0';
    pos->x++;
    pos->y = -1;
}

int my_getnbr_rec(char *str)
{
    int count = 0;

    for (int k = 0; str[k] != '\n' && str[k] != '\0'; k++) {
        count *= 10;
        count += str[k] - '0';
    }
    return count;
}

void smaller(short **nb_arr, coor_t *pos)
{

    int tmp = nb_arr[pos->x][pos->y - 1];

    if (nb_arr[pos->x - 1][pos->y - 1] < tmp)
        tmp = nb_arr[pos->x - 1][pos->y - 1];
    if (nb_arr[pos->x - 1][pos->y] < tmp)
        tmp = nb_arr[pos->x - 1][pos->y];
    nb_arr[pos->x][pos->y] = tmp + 1;
    if (pos->nbr < tmp + 1) {
        pos->nbr = tmp + 1;
        pos->mem_x = pos->x;
        pos->mem_y = pos->y;
    }
}

void init(coor_t *pos)
{
    pos->x = 0;
    pos->y = 0;
    pos->nbr = 0;
    pos->mem_x = 0;
    pos->mem_y = 0;
    pos->k = 0;
    pos->size_str = 0;
    pos->size = 0;
}
