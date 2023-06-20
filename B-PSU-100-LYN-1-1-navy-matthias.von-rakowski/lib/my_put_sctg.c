/*
** EPITECH PROJECT, 2022
** my_put_sctg
** File description:
** a short file description
*/
#include "include/my.h"

void display_sctg2(double nb, int power, char sign, char *precision)
{
    my_put_fltg(nb, precision);
    my_putchar('E');
    my_putchar(sign);
    for (int i = 0; i < 2 - size_int(power); i++)
        my_putchar('0');
    my_put_nbr(power);
}

void display_sctg(double nb, int power, char sign, char *precision)
{
    my_put_fltg(nb, precision);
    my_putchar('e');
    my_putchar(sign);
    for (int i = 0; i < 2 - size_int(power); i++)
        my_putchar('0');
    my_put_nbr(power);
}

void func2(double nb, char exp, char *precision)
{
    int  power = 0;
    while (nb >= 10) {
        nb /= 10;
        power++;
    }
    if (exp == 'e')
        display_sctg(nb, power, '+', precision);
    else
        display_sctg2(nb, power, '+', precision);
}

void my_put_sctg(double nb, char exp, char *precision)
{
    int power = 0;
    nb = nb < 0 ? (-nb) : (nb);
    if (nb >= 10)
        func2(nb, exp, precision);
    while ((nb >= 0) && (nb < 1)) {
        nb *= 10;
        power++;
    }
    if (exp == 'e')
        display_sctg(nb, power, '-', precision);
    else
        display_sctg2(nb, power, '-', precision);
}
