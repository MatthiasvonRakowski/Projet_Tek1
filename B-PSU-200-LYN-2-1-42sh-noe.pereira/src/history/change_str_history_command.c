/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** change_str_history_command
*/
#include "../../include/sh42_include.h"

void change_last_com(s_42sh *sh, int i, h_info *h)
{
    int nb = 0;
    char *str = malloc(sizeof(char) * (int)(strlen(sh->com_line) +
    strlen(h->cell->prev->com) + 1));
    for (; nb < i; nb++)
        str[nb] = sh->com_line[nb];
    for (int j = 0; j < (int)strlen(h->cell->prev->com); j++) {
        str[nb] = h->cell->prev->com[j];
        nb++;
    }
    for (int h = i + 2; h < (int)strlen(sh->com_line); h++) {
        str[nb] = sh->com_line[h];
        nb++;
    }
    str[nb]++;
    free(sh->com_line);
    sh->com_line = malloc(sizeof(char) * (int)strlen(str));
    strcpy(sh->com_line, str);
}

int add_old_command(s_42sh *sh, int i, h_info *history)
{
    int check;
    if (sh->com_line[i + 1] == '!') {
        change_last_com(sh, i, history);
        return (i + 1);
    }
    if (sh->com_line[i + 1] >= '0' && sh->com_line[i + 1] <= '9') {
        check = add_com_nb(sh, i, history);
        if (check == -1)
            return (-1);
        return (check);
    }
    if (sh->com_line[i + 1] >= 33 && sh->com_line[i + 1] <= 126) {
        check = add_com_str(sh, i, history);
        if (check == -1)
            return (-1);
        return (check);
    }
    return (i);
}

int change_string_old_command(s_42sh *sh, h_info *history)
{
    int check; int nb;
    for (int i = 0; sh->com_line[i] != '\0'; i++) {
        check = 0;
        if (sh->com_line[i] == '!')
            check = add_old_command(sh, i, history);
        if (check != 0) {
            nb = 1;
            i = check;
        }
        if (check == -1)
            return (-1);
    }
    if (nb == 1)
        printf("%s\n", sh->com_line);
    return (0);
}
