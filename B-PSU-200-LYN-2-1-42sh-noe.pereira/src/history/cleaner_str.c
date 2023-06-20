/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** cleaner_str
*/
#include "../../include/sh42_include.h"

static int *move_next_char(int *ij, char *s, char *str)
{
    for (; s[ij[1]] == ' ' || s[ij[1]] == '\t'; ij[1]++);
    ij[1]--;
    if (str[ij[0] - 1] != ' ') {
        str[ij[0]] = ' ';
        ij[0]++;
    }
    return (ij);
}

static int check_parent(int j, char *str, int size)
{
    if (str[j] == '(')
        return (7);
    if (str[j] == ')')
        return (8);
    return (-1);
}

char *cleaner_str(char *s, int size)
{
    char *str = malloc(sizeof(char) * ((int)(size * 3)));
    int check; int *ij = malloc(sizeof(int) * 2);
    ij[0] = 0; ij[1] = 0; int nb;
    for (; ij[1] < size; ij[1]++) { nb = 0;
        check = check_red(ij[1], s, size);
        if (check == -1 || check == 7)
            check = check_parent(ij[1], s, size);
        if (check != -1)
            ij = add_red(str, check, ij);
        if (s[ij[1]] == ' ' || s[ij[1]] == '\t') {
            ij = move_next_char(ij, s, str); nb = 1;
        }
        if (nb != 1 && check == -1 && ij[1] < size) {
            str[ij[0]] = s[ij[1]]; ij[0]++;
        }
    }
    str[ij[0]] = '\0'; if (str[0] == ' ')
        for (int i = 0; str[i] != '\0'; i++) str[i] = str[i + 1];
    return (str);
}
