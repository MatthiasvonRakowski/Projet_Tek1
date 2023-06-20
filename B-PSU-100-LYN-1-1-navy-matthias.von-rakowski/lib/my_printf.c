/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** a short file description
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct_specifier.h"
#include "include/struct_flags.h"

char char_is_specifier(char c)
{
    if ((c >= 65) && (c <= 90))
        return 1;
    if ((c >= 97) && (c <= 122))
        return 1;
    if ((c == '%' || c == '\0'))
        return 1;
    return 0;
}

char *my_get_flags(const char *format, int *i)
{
    char *str = malloc(sizeof(format + *i + 1));
    int nbytes = 0;
    while (!char_is_specifier(*(format + *i + 1  + nbytes))) {
        nbytes++;
    }
    my_strncpy(str, format + *i + 1, nbytes);
    *i = *i + nbytes;
    return str;
}

void choice_format(const char *format, va_list args, int *ncar, int *i)
{
    int found = 0;
    flags_list FLAG = {NULL, NULL, NULL};
    char *flags = my_get_flags(format, i);
    FLAG.f = my_get_flag(flags);
    flags = (FLAG.f == NULL) ? flags : flags + my_strlen(FLAG.f);
    FLAG.w = my_get_width(flags);
    flags = (FLAG.w == NULL) ? flags : flags + my_strlen(FLAG.w);
    FLAG.p = my_get_precision(flags);
    flags = (FLAG.p == NULL) ? flags : flags + my_strlen(FLAG.p);
    for (int j = 0; j < 17; j++) {
        if (SPECIFIERS[j].specifier == format[*i + 1]) {
            SPECIFIERS[j].display(args, FLAG, ncar);
            *i = *i + 2;
            found = 1;
            break;
        }
    }
    if (found != 1)
        *i = *i + 1;
}

void display_char(const char *format, va_list args, int *ncar, int *i)
{
    if (format[*i] == '%') {
        choice_format(format, args, ncar, i);
    } else {
        my_putchar(format[*i]);
        *ncar = *ncar + 1;
        *i = *i + 1;
    }
}

int my_printf(char const *format, ...)
{
    va_list args;
    int i = 0;
    int ncar = 0;
    va_start(args, format);
    while (format[i] != '\0') {
        display_char(format, args, &ncar, &i);
    }
    va_end(args);
    return ncar;
}
