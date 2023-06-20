/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** syntax_error_bis
*/

#include "../../include/struct_42sh.h"

bool ambiguous_input(char *str, char *err)
{
    int nb_redir = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<' && str[i + 1] != '<') {
            nb_redir++;
        }
        if (str[i] == '<' && str[i + 1] == '<') {
            i++; nb_redir++;
        }
        if (str[i] == '|' && nb_redir == 0) {
            nb_redir++;
        }
        if (str[i] == '>') { nb_redir--;
        }
        if (str[i] == ';')
            nb_redir = 0;
        if (nb_redir >= 2) {
            write(2, err, 27); return (true);
        }
    }
    return (false);
}
