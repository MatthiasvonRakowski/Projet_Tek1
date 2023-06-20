/*
** EPITECH PROJECT, 2022
** try
** File description:
** Write a number
*/

int my_putchar_count (char c);

int my_putstr_count (char *str);

int my_put_nbr_count (int n)
{
    int count = 0;

    if (n < 0) {
        count += my_putchar_count('-');
        n = -n;
    }
    if (n >= 10)
        count += my_put_nbr_count(n / 10);
    count += my_putchar_count('0' + (n % 10));
    return count;
}
