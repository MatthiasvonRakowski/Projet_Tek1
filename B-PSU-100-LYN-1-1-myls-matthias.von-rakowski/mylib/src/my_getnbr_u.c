/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** Return the first number see that
*/

#include "../include/printf.h"

unsigned int that_number_i_u(char const *str)
{
    int i = 0;
    unsigned int soluce = 0;

    if (str[i] == '0') {
        for (; str[i] == '0'; i++);
        that_number_i_u(&str[i]);
    }
    for (; str[i] >= '0' && str[i] <= '9' && i <= 11; i++) {
        soluce -= (str[i] - '0');
        if (i < 10 && str[i + 1] >= '0' && str[i + 1] <= '9') {
            soluce *= 10;
        }
    }
    return soluce;
}

unsigned long that_number_u(char const *str)
{
    int i = 0;
    unsigned long soluce = 0;

    if (str[i] == '0') {
        for (; str[i] == '0'; i++);
        that_number_u(&str[i]);
    }
    for (; str[i] >= '0' && str[i] <= '9' && i <= 11; i++) {
        soluce -= (str[i] - '0');
        if (i < 10 && str[i + 1] >= '0' && str[i + 1] <= '9') {
            soluce *= 10;
        }
    }
    return soluce;
}

unsigned int that_test_u(unsigned long you, unsigned int s)
{
    if (you == s) {
        return s;
    }
    return 0;
}

unsigned int my_getnbr_u(char const *str)
{
    int i = 0;
    unsigned long you = 0;
    unsigned int soluce = 0;

    for (; str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'); i++) {
        if (str[i] == '-') {
            soluce++;
        }
    }
        you = that_number_u(&str[i]);
        soluce = that_number_i_u(&str[i]);

    return (that_test_u(you, soluce));
}
