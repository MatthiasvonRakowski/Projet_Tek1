/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** Read a string letter by letter.
*/

int my_putchar_count (char c);

int my_putstr_count (char const *str)
{
    int count = 0;
    for (int n = 0; str[n] != '\0'; n++) {
        count += my_putchar_count (str[n]);
    }
    return count;
}
