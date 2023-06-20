/*
** EPITECH PROJECT, 2023
** antman
** File description:
** write_one_char
*/

#include "antman.h"

int write_one_char(char c, lz_t *lz)
{
    lz->final_str[lz->pos_f_buff++] = c;
    lz->final_str[lz->pos_f_buff] = '\0';
    return 0;
}
