/*
** EPITECH PROJECT, 2022
** size_flt
** File description:
** a short file description
*/

#include <stddef.h>
#include "include/my.h"

int size_bin(int nb)
{
    int count = 0;
    while (nb != 0) {
        nb /= 2;
        count++;
    }
    return count;
}

int size_oct(int a)
{
    int count = 0;
    while (a >= 9) {
        a /= 8;
        count++;
    }
    count++;
    return count;
}

int size_flt(double a, int precision)
{
    int len = size_int((int) a);
    if (precision != 0)
        len += precision + 1;
    else
        len = len;
    return len;
}

void convert_sct(double *a)
{
    while (*a >= 10)
        *a = *a / 10;
    while ((*a >= 0) && (*a < 1))
        *a = *a * 10;
}

int size_sct(double a, int precision)
{
    a = a < 0 ? (-a) : (a);
    convert_sct(&a);
    int len = size_int((int) a);
    if (precision != 0)
        len += precision + 5;
    else
        len += precision + 4;
    return len;
}
