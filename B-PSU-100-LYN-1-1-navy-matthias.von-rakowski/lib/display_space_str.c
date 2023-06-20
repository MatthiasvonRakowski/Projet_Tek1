/*
** EPITECH PROJECT, 2022
** display_space_str
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int disp_str_a(int a, flags_list FLAG)
{
    if ((FLAG.w == NULL) || (find_f(FLAG.f, '-')))
        return 0;
    int nb_space = convert_number(FLAG.w);
    int occ = nb_space - a;
    for (int i = 0; i < occ; i++)
        my_putchar(' ');
    if (occ < 0)
        return 0;
    return occ;
}

int disp_str_b(int a, flags_list FLAG)
{
    if ((FLAG.w == NULL) || (!find_f(FLAG.f, '-')))
        return 0;
    int	nb_space = convert_number(FLAG.w);
    int	occ = nb_space - a;
    for (int i = 0; i < occ; i++)
        my_putchar(' ');
    if (occ < 0)
        return 0;
    return occ;
}
