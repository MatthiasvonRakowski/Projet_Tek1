/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** function printf
*/

#include "../include/printf.h"

char *print_bonus(char *format, va_list arg, printf_t *pr)
{
    char *str = va_arg(arg, char *);
    int k = 0;

    my_putchar('\n', pr);
    for (int i = 0; str[k] != '\0'; i += 16) {
        if(i < 16) {
            for (k = 0; k < 7; k++) {
                my_putchar('0', pr);
            }
            my_putnbr_base(i, "0123456789abcdef", pr);
            my_putstr("0 :", pr);
        } else { 
                for (k = 0; k < 7; k++) {
                    my_putchar('0', pr);
                }
                my_putnbr_base(i, "0123456789abcdef", pr);
                my_putstr(" :", pr);
        }
        for (k = i; str[k] != '\0' && k < (i + 16); k++) {
            if (k % 2 == 0)
                my_putchar(' ', pr);
            if (str[k] < 16)
                my_putchar('0', pr);
            my_putnbr_base(str[k], "0123456789ABCDEF", pr);
        }
        if (str[k] == '\0')
            for (int z = k; z < i + 16; z++) {
                my_putchar(' ', pr);
                my_putchar(' ', pr);
                if (z % 2 == 0)
                    my_putchar(' ', pr);
            }
        my_putchar(' ', pr);
        for (k = i; str[k] != '\0' && k < (i + 16); k++) {
            if (str[k] < 32 || str[k] == 127)
                my_putchar('.', pr);
            else
                my_putchar(str[k], pr);
        }
        my_putchar('\n', pr);
    }
    return format;
}

char *check_final_flag(char *format, va_list arg, printf_t *pr)
{
    switch (*format) {
        case 'g': format = print_g(format, arg, pr); break;
        case 'G': format = print_big_g(format, arg, pr); break;
        case 'p': format = print_pointers(format, arg, pr); break;
        case 'e': format = print_scientific(format, arg, pr); break;
        case 'E': format = print_scientific_big(format, arg, pr); break;
        case 'n': format = print_n(format, arg, pr); break;
        default: format = preflag(format, arg, pr); break;
    }
    return (format);
}

char *check_other_flag(char *format, va_list arg, printf_t *pr)
{
    switch (*format) {
        case 'o': format = print_octal(format, arg, pr); break;
        case 'h': format = print_short(format, arg, pr); break;
        case '%': format = print_percent(format, arg, pr); break;
        case 'b': format = print_unsigned_binary(format, arg, pr); break;
        case 'f': format = print_float(format, arg, pr); break;
        case 'X': format = print_hexa_capital(format, arg, pr); break;
        case 'u': format = print_usigned(format, arg, pr); break;
        default: format = check_final_flag(format, arg, pr); break;
    }
    return (format);
}

char *check_flag(char *format, va_list arg, printf_t *pr)
{
    switch (*format) {
        case 'i':
        case 'd': format = print_int(format, arg, pr); break;
        case 'l': format = print_long_int(format, arg, pr); break;
        case 'c': format = print_char(format, arg, pr); break;
        case 's': format = print_str(format, arg, pr); break;
        case 'S': format = print_big_s(format, arg, pr); break;
        case 'x': format = print_hexa(format, arg, pr); break;
        case 'A': format = print_float_hexa_big(format, arg, pr); break;
        case 'a': format = print_float_hexa(format, arg, pr); break;
        case 'w': format = print_bonus(format, arg, pr); break;
        default: format = check_other_flag(format, arg, pr); break;
    }
    return (format);
}

char *test(char *format, va_list arg, printf_t *pr)
{
    if (*format == '%' || parcer(pr)) {
        if (*format == '%')
            format++;
        format = check_flag(format, arg, pr);
    } else {
        my_putchar(*format, pr);
    }
    return (format);
}

int my_printf(char *format, ...)
{
    printf_t *print = malloc(sizeof(printf_t));
    init_struct(print);
    hold_string(format, print);
    print->retur = 0;

    print->retur = 0;
    va_list arg;
    va_start(arg, format);
    for (; *format != '\0'; format++)
        format = test(format, arg, print);
    va_end(arg);
    return (print->retur);
}
