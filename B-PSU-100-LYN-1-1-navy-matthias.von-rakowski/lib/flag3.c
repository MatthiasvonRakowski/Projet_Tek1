/*
** EPITECH PROJECT, 2022
** flag3
** File description:
** a short file description
*/

#include <stdarg.h>
#include "include/my.h"
#include <stddef.h>

void disp_f(va_list args, flags_list FLAG, int *ncar)
{
    double a = va_arg(args, double);
    *ncar = *ncar + disp_flt_a(a, FLAG);
    *ncar = *ncar + my_put_sign((int) a, FLAG.f);
    *ncar = *ncar + display_zero_float(a, FLAG);
    int p = FLAG.p == NULL ? 6 : convert_number(FLAG.p);
    *ncar = *ncar + size_flt(a, p);
    my_put_float(a, FLAG.p);
    *ncar = *ncar + disp_flt_b(a, FLAG);
}

void disp_e(va_list args, flags_list FLAG, int *ncar)
{
    double a = va_arg(args, double);
    *ncar = *ncar + disp_sct_a(a, FLAG);
    *ncar = *ncar + my_put_sign((int) a, FLAG.f);
    *ncar = *ncar + display_zero_sct(a, FLAG);
    int p = FLAG.p == NULL ? 6 : convert_number(FLAG.p);
    *ncar = *ncar + size_sct(a, p);
    my_put_scientific(a, 'e', FLAG.p);
    *ncar = *ncar + disp_sct_b(a, FLAG);
}

void disp_ee(va_list args, flags_list FLAG, int *ncar)
{
    double a = va_arg(args, double);
    *ncar = *ncar + disp_sct_a(a, FLAG);
    *ncar = *ncar + my_put_sign((int) a, FLAG.f);
    *ncar = *ncar + display_zero_sct(a, FLAG);
    int p = FLAG.p == NULL ? 6 : convert_number(FLAG.p);
    *ncar = *ncar + size_sct(a, p);
    my_put_scientific(a, 'E', FLAG.p);
    *ncar = *ncar + disp_sct_b(a, FLAG);
}

void disp_n(va_list args, flags_list FLAG, int *ncar)
{
    int *a = va_arg(args, int *);
    if (a)
        *a = *ncar;
}

void disp_p(va_list args, flags_list FLAG, int *ncar)
{
    long long a = va_arg(args, long long);
    *ncar = *ncar + disp_space_hexa_before(a, FLAG);
    *ncar = *ncar + my_reputstr("0x");
    *ncar = *ncar + display_zero(get_hexa_len(a, FLAG.f), FLAG);
    *ncar = *ncar + my_put_adress('y', a, 'x');
    *ncar = *ncar + disp_space_hexa_after(a, FLAG);
}
