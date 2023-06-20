/*
** EPITECH PROJECT, 2022
** flag2
** File description:
** a short file description
*/

#include <stdarg.h>
#include "include/my.h"
#include <stddef.h>

void disp_u(va_list args, flags_list FLAG, int *ncar)
{
    int a = va_arg(args, unsigned int);
    *ncar = *ncar + disp_int_a(a, FLAG);
    *ncar = *ncar + display_zero(size_int(a), FLAG);
    *ncar = *ncar + my_put_nbr(a);
    *ncar = *ncar + disp_int_b(a, FLAG);
}

void disp_x(va_list args, flags_list FLAG, int *ncar)
{
    int a = va_arg(args, int);
    *ncar = *ncar + disp_space_hexa_before(a, FLAG);
    *ncar = *ncar + my_put_suffix("0x", FLAG.f);
    *ncar = *ncar + display_zero(get_hexa_len(a, FLAG.f), FLAG);
    *ncar = *ncar + my_put_hexa('y', a, 'x');
    *ncar = *ncar + disp_space_hexa_after(a, FLAG);
}

void disp_xx(va_list args, flags_list FLAG, int *ncar)
{
    int a = va_arg(args, int);
    *ncar = *ncar + disp_space_hexa_before(a, FLAG);
    *ncar = *ncar + my_put_suffix("0X", FLAG.f);
    *ncar = *ncar + display_zero(get_hexa_len(a, FLAG.f), FLAG);
    *ncar = *ncar + my_put_hexa('y', a, 'X');
    *ncar = *ncar + disp_space_hexa_after(a, FLAG);
}

void disp_ss(va_list args, flags_list FLAG, int *ncar)
{
    char *a = va_arg(args, char*);
    *ncar = *ncar + flag_s(a);
}

void disp_b(va_list args, flags_list FLAG, int *ncar)
{
    int a = va_arg(args, int);
    *ncar = *ncar + size_bin(a);
    my_put_bin(a);
}
