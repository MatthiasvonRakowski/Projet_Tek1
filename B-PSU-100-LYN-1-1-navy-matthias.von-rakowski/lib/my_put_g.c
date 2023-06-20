/*
** EPITECH PROJECT, 2022
** my_put_g
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int my_get_power(double a)
{
    int power = 0;
    a = a < 0 ? (-a) : (a);
    while (a >= 10) {
        power++;
        a /= 10;
    }
    while ((a >= 0) && (a < 1)) {
        power--;
        a *= 10;
    }
    return power;
}

void my_put_g(double a, char *p)
{
    if (p == NULL) {
        if ((my_get_power(a) < -4) || (my_get_power(a) >= 6)) {
            my_put_sctg(a, 'e', p);
        } else
            my_put_fltg(a, p);
    } else {
        if ((my_get_power(a) < -4) || (my_get_power(a) >= convert_number(p))) {
            my_put_sctg(a, 'e', p);
        } else {
            my_put_fltg(a, p);
        }
    }
}
