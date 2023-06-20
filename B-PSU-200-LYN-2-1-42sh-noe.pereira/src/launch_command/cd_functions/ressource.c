/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** ressource
*/
#include "../../../include/sh42_include.h"

void my_copy(char *str, char *str1, char *str2)
{
    int nb = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        str[nb] = str1[i];
        nb++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        str[nb] = str2[i];
        nb++;
    }
}

int my_compare_str(char const *s1, char const *s2, int n)
{
    int rang = 0;
        while ((s1[rang] != '\0' || s1[rang] != '\0') && rang < n) {
        if (s1[rang] < s2[rang])
            return (-1);
        if (s1[rang] > s2[rang])
            return (1);
        rang++;
        }
    return (0);
}

int size_env_line(char *str)
{
    int i = strlen(str) - 1;
    for (; i >= 0; i--)
        if (str[i] == '=')
            break;
    return (i);
}
