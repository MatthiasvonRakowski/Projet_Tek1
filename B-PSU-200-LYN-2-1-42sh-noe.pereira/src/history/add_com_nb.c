/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** add_com_str
*/
#include "../../include/sh42_include.h"

void cpy_str(int i, s_42sh *sh, h_info *h, char *str)
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

int find_number_command(int *yoo, h_info *h, int i, s_42sh *sh)
{
    h_cell *start = h->cell; int v = 0;
    for (; v < h->size; v++) {
        if (h->cell->nb_com == yoo[0])
            break;
        h->cell = h->cell->next;
    }
    if (v == h->size) { h->cell = start; return (-1);
    }
    char *str = malloc(sizeof(char) * (int)(strlen(sh->com_line) +
    strlen(h->cell->com) + 1));
    cpy_str(i, sh, h, str);
    free(sh->com_line);
    sh->com_line = malloc(sizeof(char) * (int)strlen(str));
    strcpy(sh->com_line, str);
    free(str);
    h->cell = start;
    return (0);
}

int check_alpha(char *str)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] > '9' || str[j] < '0') {
            write(2, str, strlen(str));
            write(2, ": Event not found.\n", 19);
            free(str);
            return (-1);
        }
    }
    return (0);
}

int add_com_nb(s_42sh *sh, int i, h_info *h)
{
    int n = i + 1; int *yoo = malloc(sizeof(int) * 2); int nb = 1;
    for (; sh->com_line[n] != ' ' && sh->com_line[n] != '\t' &&
    sh->com_line[n] != '\0' && sh->com_line[n] != '!'; n++)
        nb++;
    char *str = malloc(sizeof(char) * (nb));
    for (int j = i + 1; j < i + nb; j++)
        str[j - i - 1] = sh->com_line[j];
    str[nb - 1] = '\0';
    if (check_alpha(str) == -1)
        return (-1);
    sscanf(str, "%d", &yoo[0]);
    yoo[1] = (int)strlen(str);
    if (find_number_command(yoo, h ,i , sh) == -1) {
        write(2, str, strlen(str));
        write(2, ": Event not found.\n", 19);
        free(str); free(yoo);
        return (-1);
    }
    free(str); free(yoo);
    return (n - 1);
}
