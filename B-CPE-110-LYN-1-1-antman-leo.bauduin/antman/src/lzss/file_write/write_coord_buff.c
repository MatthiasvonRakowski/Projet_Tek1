/*
** EPITECH PROJECT, 2023
** antman
** File description:
** write_coord_buff
*/

#include "antman.h"

int write_coord_buff(int pos, int size, lz_t *lz)
{
    lz->final_str[lz->pos_f_buff++] = '\n';
    lz->final_str[lz->pos_f_buff] = '\0';
    printf("WOUHOUOUUU");
    return 0;
}
