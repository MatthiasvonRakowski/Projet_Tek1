/*
** EPITECH PROJECT, 2022
** disp_space_str
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int disp_space_hexa_before(int a, flags_list FLAG)
{
    int nb_space = 0;
    if ((FLAG.w == NULL) || (find_f(FLAG.f, '-')) || (find_f(FLAG.f, '0')))
        return 0;
    if (FLAG.p != NULL) {
        if (convert_number(FLAG.p) >= get_hexa_len(a, FLAG.f))
            nb_space = convert_number(FLAG.p);
        else
            nb_space = get_hexa_len(a, FLAG.f);
    } else
        nb_space = get_hexa_len(a, FLAG.f);
    if (a < 0)
        nb_space++;
    if (find_f(FLAG.f, '#'))
        nb_space += 2;
    int occ = convert_number(FLAG.w) - nb_space;
    for (int i = 0; i < occ; i++, my_putchar(' '));
    occ = occ < 0 ? 0 : occ;
    return occ;
}

int disp_space_hexa_after(int a, flags_list FLAG)
{
    int nb_space = 0;
    if ((FLAG.w == NULL) || (!find_f(FLAG.f, '-')))
        return 0;
    if (FLAG.p != NULL) {
        if (convert_number(FLAG.p) >= get_hexa_len(a, FLAG.f))
            nb_space = convert_number(FLAG.p);
        else
            nb_space = get_hexa_len(a, FLAG.f);
    } else
        nb_space = get_hexa_len(a, FLAG.f);
    if (a < 0)
        nb_space++;
    int occ = convert_number(FLAG.w) - (nb_space);
    for (int i = 0; i < occ; i++)
        my_putchar(' ');
    occ = occ < 0 ? 0 : occ;
    return occ;
}
