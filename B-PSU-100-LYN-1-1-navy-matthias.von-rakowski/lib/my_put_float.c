/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

void display_zero_flt(double *nb_dec, int *count, int p)
{
    if ((p != 0) && (*nb_dec != 0)) {
        while ((*nb_dec < 0.1) && (*count < p - 1)) {
            my_put_nbr(0);
            *nb_dec = *nb_dec * 10;
            *count = *count + 1;
        }
    }
}

void display_nb_dec(double *nb_dec, int *count, int p)
{
    while (*count < p - 1) {
        my_put_nbr(0);
        *count = *count + 1;
    }
    if (p != 0)
        my_put_nbr(*nb_dec);
}

void my_put_float(double nb, char *precision)
{
    int p = 0;
    nb = nb < 0 ? (-nb) : (nb);
    if (precision != NULL)
        p = convert_number(precision);
    else
        p = 6;
    int count = 0;
    int first_part = (int) nb;
    double nb_dec = ((nb - (double) first_part));
    my_put_nbr(first_part);
    if (p != 0)
        my_putchar('.');
    display_zero_flt(&nb_dec, &count, p);
    while ((count < p) && (nb_dec != 0)) {
        nb_dec *= 10;
        count++;
    }
    display_nb_dec(&nb_dec, &count, p);
}
