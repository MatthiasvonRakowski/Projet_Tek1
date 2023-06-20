/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** add_com_str
*/
#include "../../include/sh42_include.h"

int my_comp(char *str, char *str1, int n)
{
    int nb = 0;
    for (; nb < n; nb++) {
        if (str[nb] != str1[nb]) {
            return (-1);
        }
    }
    return (0);
}

void cpy_strr(int i, s_42sh *sh, char *str, h_info *h)
{
    int nb = 0;
    for (; nb < i; nb++)
        str[nb] = sh->com_line[nb];
    for (int j = 0; j < (int)strlen(h->cell->com); j++) {
        str[nb] = h->cell->com[j];
        nb++;
    }
    for (int h = i + 2; h < (int)strlen(sh->com_line); h++) {
        str[nb] = sh->com_line[h];
        nb++;
    }
    str[nb] = '\0';
}

int find_string_command(s_42sh *sh, int i, h_info *h, char *st)
{
    h_cell *start = h->cell; int v = 0;
    h->cell = h->cell->prev;
    for (; v < h->size; v++) {
        if (my_comp(st, h->cell->com,(int)strlen(st)) == 0) {
            break;
        }
        h->cell = h->cell->prev;
    }
    if (v == h->size) { h->cell = start; return (-1);
    }
    char *str = malloc(sizeof(char) * ((int)(strlen(sh->com_line) +
    (int)strlen(h->cell->com) + 1)));
    cpy_strr(i, sh, str, h);
    free(sh->com_line);
    sh->com_line = malloc(sizeof(char) * (int)strlen(str));
    strcpy(sh->com_line, str);
    free(str);
    h->cell = start;
    return (0);
}

int add_com_str(s_42sh *sh, int i, h_info *h)
{
    int n = i + 1; int nb = 1;
    for (; sh->com_line[n] != ' ' && sh->com_line[n] != '\t' &&
    sh->com_line[n] != '\0'; n++) nb++;
    char *str = malloc(sizeof(char) * (nb));
    for (int j = i + 1; j < i + nb; j++) {
        str[j - i - 1] = sh->com_line[j];
    }
    str[nb - 1] = '\0';
    if (find_string_command(sh, i, h, str) == -1) {
        write(2, str, strlen(str));
        write(2, ": Event not found.\n", 19);
        free(str);
        return (-1);
    }
    free(str);
    return (i + nb - 1);
}
