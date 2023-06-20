/*
** EPITECH PROJECT, 2022
** my
** File description:
** a short file description
*/

#ifndef MY_
    #define MY_

    #include <stdarg.h>
    #include "struct_flags.h"
    #include <signal.h>
    #include <stddef.h>

int my_char_is_printable(char c);

int my_str2dlen(char **array);

int my_printf(char const *format, ...);

void disp_c(va_list args, flags_list FLAG, int *ncar);

int display_zero(int nb, flags_list FLAG);

void display_zero_flt(double *nb_dec, int *count, int p);

int display_zero_float(double nb, flags_list FLAG);

int display_zero_sct(double nb, flags_list FLAG);

void display_scientific2(double nb, int power, char sign, char *precision);

char *my_strncpy(char *dest, char const *src, int n);

char find_f(char *flag, char to_find);

char *my_get_flag(char *flags);

char *my_get_width(char *flags);

char *my_get_precision(char *flags);

int my_put_suffix(char *choice, char *flag);

int my_put_sign(int nb, char *flag);

int disp_flt_a(double a, flags_list FLAG);

int disp_flt_b(double a, flags_list FLAG);

int disp_sct_a(double a, flags_list FLAG);

int disp_sct_b(double a, flags_list FLAG);

int disp_str_a(int a, flags_list FLAG);

int disp_str_b(int a, flags_list FLAG);

int disp_int_a(int a, flags_list FLAG);

int disp_int_b(int a, flags_list FLAG);

int disp_oct_a(int a, flags_list FLAG);

int disp_oct_b(int a, flags_list FLAG);

int disp_space_hexa_before(int nb, flags_list FLAG);

int disp_space_hexa_after(int nb, flags_list FLAG);

int convert_number(char *str_nb);

char char_is_number(char c);

void disp_s(va_list args, flags_list FLAG, int *ncar);

void disp_ss(va_list args, flags_list FLAG, int *ncar);

void disp_x(va_list args, flags_list FLAG, int *ncar);

void disp_xx(va_list args, flags_list FLAG, int *ncar);

void disp_d(va_list args, flags_list FLAG, int *ncar);

void disp_u(va_list args, flags_list FLAG, int *ncar);

void disp_o(va_list args, flags_list FLAG, int *ncar);

void disp_b(va_list args, flags_list FLAG, int *ncar);

void disp_prc(va_list args, flags_list FLAG, int *ncarr);

void disp_f(va_list args, flags_list FLAG, int *ncar);

void disp_e(va_list args, flags_list FLAG, int *ncar);

void disp_ee(va_list args, flags_list FLAG, int *ncar);

void disp_n(va_list args, flags_list FLAG, int *ncar);

void disp_p(va_list args, flags_list FLAG, int *ncar);

void disp_g(va_list args, flags_list FLAG, int *ncar);

void test_neg(double *nb);

void func1(double nb, char exp, char *precision);

void my_put_scientific(double nb, char exp, char *precision);

void my_put_float(double nb, char *precision);

char display_letter_hexa_min(int nb);

char display_letter_hexa_maj(int nb);

char display_letter_hexa(int nb, char type);

void print_hexa(char print, int nb, char *str);

int my_put_hexa(char print, int nb, char type);

int get_hexa_len(int nb, char *flag);

int display_non_printable(char c);

int flag_s(char *str);

void my_put_bin(int nb);

int my_strlen(char const *str);

int my_strnlen(char const *str, char *precision);

char *my_evil_str(char *str);

int my_putchar(char c);

int my_put_nbr(int nb);

int size_int(int nb);

int size_flt(double a, int precision);

int size_sct(double a, int precision);

int size_oct(int a);

int size_bin(int nb);

void convert_sct(double *a);

int my_put_oct(int nb);

int my_reputstr(char const *str);

int my_reputnstr(char const *str, char *precision);

long long my_put_adress (char print, long long nb, char type);

void my_put_fltg(double nb, char *precision);

void my_put_sctg(double nb, char exp, char *precision);

void my_put_g(double a, char *p);

#endif /* MY_ */
