/*
** EPITECH PROJECT, 2022
** POOL
** File description:
** flag4.c
*/

#include <stdarg.h>
#include "include/my.h"
#include <stddef.h>

void disp_g(va_list args, flags_list FLAG, int *ncar)
{
    double a = va_arg(args, double);
    my_put_g(a, FLAG.p);
}
