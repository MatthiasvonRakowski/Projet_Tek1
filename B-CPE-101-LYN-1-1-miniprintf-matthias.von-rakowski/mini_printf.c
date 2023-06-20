/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** introduction to the printf
*/

#include<stdarg.h>
#include<unistd.h>

int my_putchar_count (char c);
int my_putstr_count (char *str);
int my_put_nbr_count (int nbr);

int the_switch_case (char const *c, va_list list, int i)
{
    int count = 0;

    switch (c[i]) {
        case 'i':
            count += my_put_nbr_count(va_arg(list, int)); break;
        case 'd':
            count += my_put_nbr_count(va_arg(list, int)); break;
        case 's':
            count += my_putstr_count(va_arg(list, char *)); break;
        case 'c':
            count += my_putchar_count(va_arg(list, int)); break;
        case '%':
            count += my_putchar_count('%'); break;
        default:
            count += my_putchar_count('%');
            count += my_putchar_count(c[i]);
    };
    return count;
}

int mini_printf (const char *format, ...)
{
    va_list list;
    int count = 0;
    int flag = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            count += the_switch_case(format, list, i);
        } else {
            count += my_putchar_count(format[i]);
            }
    }
    if (count == 84)
        return (-84);
    return (count + 1);
}
