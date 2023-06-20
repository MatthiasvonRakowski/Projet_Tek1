/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** my_strtok
*/

#include "my.h"

static bool string_ncomp(char const *s1, char const *s2, int s)
{
    if (s > my_strlen(s1) || s > my_strlen(s2))
        return false;
    for (int i = 0; i < s; i++) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

bool my_strtok(char *str, char const *tf)
{
    int tf_size = my_strlen(tf);

    for (int i = 0; str[i + (tf_size - 1)]; i++) {
        if (string_ncomp(str + i, tf, tf_size))
            return true;
    }
    return false;
}
