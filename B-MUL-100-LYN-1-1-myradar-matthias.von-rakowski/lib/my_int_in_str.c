/*
** EPITECH PROJECT, 2023
** lib/my_int_in_str
** File description:
** return a str of the number send
*/

#include <stdlib.h>
#include <stdio.h>

int my_compute_power(int nbr, int size);

char *my_int_in_str(int nbr)
{
    char *str;
    int size = 1;
    int temp;

    for (int i = nbr; i >= 10; i /= 10, size++);
    str = malloc(sizeof(char) * size);
    str[size] = '\0';
    for (int i = 0; size > 0; i++, size--) {
        temp = nbr / my_compute_power(10, size - 1);
        str[i] = temp + '0';
        nbr -= temp * my_compute_power(10, size - 1);
    }
    return str;
}
