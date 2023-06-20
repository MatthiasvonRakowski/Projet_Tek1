/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** syntax_error
*/

#include "../../include/struct_42sh.h"
#include "syntax_error.h"

static char *set_str(char *cmd)
{
    char *str = malloc(sizeof(char) * strlen(cmd) + 1);
    strcpy(str, cmd);
    str = clean_str(str);
    str = rm_allspace(str);
    return (str);
}

static bool invalid_null(char *str, char *err, int i)
{
    if (str[i] == '|' && str[i + 1] == '|' && str[i + 2] == '|') {
        write(2, err, 22); return (true);
    }
    if (str[i] == '|' && str[i + 1] == '|' && str[i + 2] == '\0') {
        write(2, err, 22); return (true);
    }
    if (str[i] == '|' && str[i + 1] == ';') {
        write(2, err, 22); return (true);
    }
    if (str[i] == ';' && str[i + 1] == '|') {
        write(2, err, 22); return (true);
    }
    if (str[i] == '|' && str[i + 1] == '\0') {
        write(2, err, 22); return (true);
    }
    if (str[i] == '&' && str[i + 1] == '&' && str[i + 2] == '\0') {
        write(2, err, 22); return (true);
    }
    return (false);
}

static bool missing_name(char *str, char *err, int i)
{
    if (str[i] == '>' && str[i + 1] == '\0') {
        write(2, err, 27); return (true);
    }
    if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '\0') {
        write(2, err, 27); return (true);
    }
    if (str[i] == '<' && str[i + 1] == '\0') {
        write(2, err, 27); return (true);
    }
    if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '\0') {
        write(2, err, 27); return (true);
    }
    if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<') {
        write(2, err, 27); return (true);
    }
    if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>') {
        write(2, err, 27); return (true);
    }
    return (false);
}

static bool ambiguous_output(char *str, char *err)
{
    int nb_redir = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '>' && str[i + 1] != '>') {
            nb_redir++;
        }
        if (str[i] == '>' && str[i + 1] == '>') {
            i++; nb_redir++;
        }
        if (str[i] == '<') {
            nb_redir--;
        }
        if (str[i] == ';')
            nb_redir = 0;
        if (nb_redir >= 2) {
            write(1, err, 27); return (true);
        }
    }
    return (false);
}

bool error_syntax(char *cmd)
{
    char *str = set_str(cmd);
    char *err = "Invalid null command.\n";
    char *err1 = "Missing name for redirect.\n";
    char *err2 = "Ambiguous output redirect.\n";
    char *err3 = "Ambiguous input redirect.\n";

    if (str[0] == '|') { write(1, err, 22); return (true); }
    for (int i = 0; str[i] != '\0'; i++) {
        if (invalid_null(str, err, i) == true)
            return (true);
        if (missing_name(str, err1, i) == true)
            return (true);
    }
    if (ambiguous_output(str, err2) == true)
        return (true);
    if (ambiguous_input(str, err3) == true)
        return (true);
    return (false);
}
