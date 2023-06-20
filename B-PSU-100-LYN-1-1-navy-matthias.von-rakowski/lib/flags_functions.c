/*
** EPITECH PROJECT, 2022
** flags_functions
** File description:
** a short file description
*/

#include <stdarg.h>
#include <unistd.h>
#include "include/my.h"

int my_put_suffix(char *choice, char *flag)
{
    if (!find_f(flag, '#'))
        return 0;
    my_reputstr(choice);
    return my_strlen(choice);
}

int my_put_sign(int nb, char *flag)
{
    if (find_f(flag, '+')) {
        if (nb >= 0) {
            my_putchar('+');
            return 1;
        }
    }
    if ((find_f(flag, ' ') && (nb >= 0))) {
        my_putchar(' ');
        return 1;
    }
    if (nb < 0) {
        my_putchar('-');
        return 1;
    }
    return 0;
}

int display_zero(int nb, flags_list FLAG)
{
    if ((FLAG.w == NULL) && (FLAG.p == NULL) || find_f(FLAG.f, '-'))
        return 0;
    int nb_zero = 0;
    int tqt = 0;
    if (FLAG.p != NULL) {
        if (convert_number(FLAG.p) >= nb)
            nb_zero = convert_number(FLAG.p) - nb;
        else {
            nb_zero = nb;
            tqt++;
        }
    }
    if ((tqt == 1) && (find_f(FLAG.f, '-')))
        return 0;
    if ((FLAG.w != NULL) && (FLAG.p == NULL) && (find_f(FLAG.f, '0')))
        nb_zero += convert_number(FLAG.w) - nb;
    for (int i = 0; i < nb_zero; i++)
        my_putchar('0');
    nb_zero = nb_zero < 0 ? 0 : nb_zero;
    return nb_zero;
}
