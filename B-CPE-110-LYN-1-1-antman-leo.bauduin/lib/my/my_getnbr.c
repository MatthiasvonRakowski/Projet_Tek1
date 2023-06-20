/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-leo.bauduin
** File description:
** mygetnbr
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_getnbr(char const *str)
{
    int len = my_strlen(str);
    int count = 0;
    int result = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == '-') {
            count += 1;
        }
        result += str[i];
        result *= 10;
    }
    if (count < 0) {
        result *= -1;
    }
    return result;
}
