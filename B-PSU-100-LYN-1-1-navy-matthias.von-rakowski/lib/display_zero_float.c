/*
** EPITECH PROJECT, 2022
** display_zero_float
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int display_zero_float(double nb, flags_list FLAG)
{
    if ((FLAG.w == NULL) || (!find_f(FLAG.f, '0')))
        return 0;
    int nb_zero = 0;
    if (FLAG.p != NULL) {
        nb_zero = convert_number(FLAG.w) - size_flt(nb, convert_number(FLAG.p));
    } else {
        nb_zero = convert_number(FLAG.w) - size_flt(nb, 6);
    }
    for (int i = 0; i < nb_zero; i++)
        my_putchar('0');
    nb_zero = nb_zero < 0 ? 0 : nb_zero;
    return nb_zero;
}

int display_zero_sct(double nb, flags_list FLAG)
{
    if ((FLAG.w == NULL) || (!find_f(FLAG.f, '0')))
        return 0;
    int nb_zero = 0;
    if (FLAG.p != NULL) {
        nb_zero = convert_number(FLAG.w) - size_sct(nb, convert_number(FLAG.p));
    } else {
        nb_zero = convert_number(FLAG.w) - size_sct(nb, 6);
    }
    for (int i = 0; i < nb_zero; i++)
        my_putchar('0');
    nb_zero = nb_zero < 0 ? 0 : nb_zero;
    return nb_zero;
}
