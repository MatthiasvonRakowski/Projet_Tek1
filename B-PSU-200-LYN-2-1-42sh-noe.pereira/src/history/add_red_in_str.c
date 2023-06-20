/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** add_red_in_str
*/
#include "../../include/sh42_include.h"

static int *add_red_next_next_next(char *str, int check, int *ij)
{
    if (check == 7) {
        if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' ';
            str[ij[0] + 1] = '(';
            str[ij[0] + 2] = ' ';
            ij[0] += 3; return (ij);
        }
        str[ij[0]] = '('; str[ij[0] + 1] = ' ';
        ij[0] += 2; return (ij);
    }
    if (check == 8) {
        if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' '; str[ij[0] + 1] = ')';
            str[ij[0] + 2] = ' ';
            ij[0] += 3; return (ij);
        }
        str[ij[0]] = ')'; str[ij[0] + 1] = ' ';
        ij[0] += 2; return (ij);
    }
    return (ij);
}

static int *add_red_next_next(char *str, int check, int *ij)
{
    if (check == 4) { if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' '; str[ij[0] + 1] = '<';
            str[ij[0] + 2] = '<'; str[ij[0] + 3] = ' '; ij[1]++;
            ij[0] += 4; return (ij);
        }
        str[ij[0]] = '<'; str[ij[0] + 1] = '<';
        str[ij[0] + 2] = ' '; ij[1]++; ij[0] += 3; return (ij);
    }
    if (check == 6) {
        if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' '; str[ij[0] + 1] = '&';
            str[ij[0] + 2] = '&'; str[ij[0] + 3] = ' '; ij[1]++;
            ij[0] += 4; return (ij);
        }
        str[ij[0]] = '&'; str[ij[0] + 1] = '&';
        str[ij[0] + 2] = ' '; ij[1]++; ij[0] += 3; return (ij);
    }
    return (add_red_next_next_next(str, check, ij));
}

static int *add_red_next(char *str, int check, int *ij)
{
    if (check == 5) { if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' '; str[ij[0] + 1] = '|';
            str[ij[0] + 2] = '|';
            str[ij[0] + 3] = ' '; ij[1]++;
            ij[0] += 4; return (ij);
        }
        str[ij[0]] = '|'; str[ij[0] + 1] = '|';
        str[ij[0] + 2] = ' '; ij[1]++;
        ij[0] += 3; return (ij);
    }
    if (check == 2) { if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' '; str[ij[0] + 1] = '>';
            str[ij[0] + 2] = '>';
            str[ij[0] + 3] = ' '; ij[1]++; ij[0] += 4; return (ij);
        }
        str[ij[0]] = '>'; str[ij[0] + 1] = '>';
        str[ij[0] + 2] = ' '; ij[1]++;
        ij[0] += 3; return (ij);
    }
    return (add_red_next_next(str, check, ij));
}

int *add_red(char *str, int check, int *ij)
{
    if (check == 0) {
        if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' ';
            str[ij[0] + 1] = '|';
            str[ij[0] + 2] = ' ';
            ij[0] += 3; return (ij);
        }
        str[ij[0]] = '|'; str[ij[0] + 1] = ' ';
        ij[0] += 2; return (ij);
    }
    if (check == 1) {
        if (str[ij[0] - 1] != ' ') {
            str[ij[0]] = ' '; str[ij[0] + 1] = '>';
            str[ij[0] + 2] = ' ';
            ij[0] += 3; return (ij);
        }
        str[ij[0]] = '>'; str[ij[0] + 1] = ' ';
        ij[0] += 2; return (ij);
    }
    return (add_red_next(str, check, ij));
}
