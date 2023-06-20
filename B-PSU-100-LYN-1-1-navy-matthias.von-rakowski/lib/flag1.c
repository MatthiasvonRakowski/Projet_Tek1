/*
** EPITECH PROJECT, 2022
** flag1
** File description:
** a short file description
*/

#include <stdarg.h>
#include "include/my.h"

void disp_c(va_list args, flags_list FLAG, int *ncar)
{
    *ncar = *ncar + disp_str_a(1, FLAG);
    *ncar = *ncar + my_putchar(va_arg(args, int));
    *ncar = *ncar + disp_str_b(1, FLAG);
}

void disp_s(va_list args, flags_list FLAG, int *ncar)
{
    char *a = va_arg(args, char *);
    *ncar = *ncar + disp_str_a(my_strnlen(a, FLAG.p), FLAG);
    *ncar = *ncar + my_reputnstr(a, FLAG.p);
    *ncar = *ncar + disp_str_b(my_strnlen(a, FLAG.p), FLAG);
}

void disp_d(va_list args, flags_list FLAG, int *ncar)
{
    int a = va_arg(args, int);
    *ncar = *ncar + disp_int_a(a, FLAG);
    *ncar = *ncar + my_put_sign(a, FLAG.f);
    *ncar = *ncar + display_zero(size_int(a), FLAG);
    *ncar = *ncar + my_put_nbr(a);
    *ncar = *ncar + disp_int_b(a, FLAG);
}

void disp_prc(va_list args, flags_list FLAG, int *ncar)
{
    *ncar = *ncar + my_putchar('%');
}

void disp_o(va_list args, flags_list FLAG, int *ncar)
{
    int a = va_arg(args, int);
    *ncar = *ncar + my_put_suffix("0", FLAG.f);
    *ncar = *ncar + disp_oct_a(a, FLAG);
    *ncar = *ncar + my_put_oct(a);
    *ncar = *ncar + disp_oct_b(a, FLAG);
}
