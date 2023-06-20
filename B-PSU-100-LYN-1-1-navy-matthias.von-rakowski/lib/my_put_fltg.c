/*
** EPITECH PROJECT, 2022
** my_put_fltg
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

void put_nbr_correct(double *nb_dec, int *count, int p)
{
    while ((*count < p) && (*nb_dec != 0)) {
        *nb_dec *= 10;
        *count = *count + 1;;
    }
}

void my_put_fltg(double nb, char *precision)
{
    int p = 0;
    int count = 0;
    int first_part = (int) nb;
    double nb_dec = ((nb - (double) first_part));
    nb = nb < 0 ? (-nb) : (nb);
    if (precision == NULL)
        p = 6 - size_int(first_part);
    else
        p = convert_number(precision) - size_int(first_part);
    my_put_nbr(first_part);
    if (p > 0)
        my_putchar('.');
    display_zero_flt(&nb_dec, &count, p);
    put_nbr_correct(&nb_dec, &count, p);
    while (((int) nb_dec % 10) == 0)
        nb_dec /= 10;
    if (p > 0)
        my_put_nbr((int) nb_dec);
}
