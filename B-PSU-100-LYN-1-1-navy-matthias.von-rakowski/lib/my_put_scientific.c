/*
** EPITECH PROJECT, 2022
** my_put_scientific
** File description:
** a short file description
*/

#include <stdio.h>
#include "include/my.h"
#include <stddef.h>

void display_scientific2(double nb, int power, char sign, char *precision)
{
    my_put_float(nb, precision);
    my_putchar('E');
    my_putchar(sign);
    for (int i = 0; i < 2 - size_int(power); i++)
        my_putchar('0');
    my_put_nbr(power);
}

void display_scientific(double nb, int power, char sign, char *precision)
{
    my_put_float(nb, precision);
    my_putchar('e');
    my_putchar(sign);
    for (int i = 0; i < 2 - size_int(power); i++)
        my_putchar('0');
    my_put_nbr(power);
}

void test_neg(double *nb)
{
    if (*nb < 0) {
        my_putchar('-');
        *nb = - *nb;
    }
}

void func1(double nb, char exp, char *precision)
{
    int  power = 0;
    while (nb >= 10) {
        nb /= 10;
        power++;
    }
    if (exp == 'e')
        display_scientific(nb, power, '+', precision);
    else
        display_scientific2(nb, power, '+', precision);
}

void my_put_scientific(double nb, char exp, char *precision)
{
    int power = 0;
    double save = nb < 0 ? (-nb) : (nb);
    while ((save >= 0) && (save < 1)) {
        save *= 10;
        power++;
    }
    if (save >= 10)
        func1(save, exp, precision);
    else if (exp == 'e')
        display_scientific(save, power, '-', precision);
    else
        display_scientific2(save, power, '-', precision);
}
