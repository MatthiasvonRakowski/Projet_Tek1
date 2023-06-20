/*
** EPITECH PROJECT, 2022
** disp_space_str
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int disp_int_a(int a, flags_list FLAG)
{
    int nb_space = 0;
    if ((FLAG.w == NULL) || (find_f(FLAG.f, '-')) || (find_f(FLAG.f, '0')))
        return 0;
    if (FLAG.p != NULL) {
        if (convert_number(FLAG.p) >= size_int(a))
            nb_space = convert_number(FLAG.p);
        else
            nb_space = size_int(a);
    } else
        nb_space = size_int(a);
    if (((find_f(FLAG.f, '+')) || (find_f(FLAG.f, ' '))) && (a >= 0))
        nb_space++;
    if (a < 0)
        nb_space++;
    int occ = convert_number(FLAG.w) - nb_space;
    for (int i = 0; i < occ; i++)
        my_putchar(' ');
    occ = occ < 0 ? 0 : occ;
    return occ;
}

int disp_int_b(int a, flags_list FLAG)
{
    int nb_space = 0;
    if ((FLAG.w == NULL) || (!find_f(FLAG.f, '-')))
        return 0;
    if (FLAG.p != NULL) {
        if (convert_number(FLAG.p) >= size_int(a))
            nb_space = convert_number(FLAG.p);
        else
            nb_space = size_int(a);
    } else
        nb_space = size_int(a);
    if ((find_f(FLAG.f, '+')) && (a >= 0))
        nb_space++;
    if (a < 0)
        nb_space++;
    int occ = convert_number(FLAG.w) - (nb_space);
    for (int i = 0; i < occ; i++)
        my_putchar(' ');
    occ = occ < 0 ? 0 : occ;
    return occ;
}
