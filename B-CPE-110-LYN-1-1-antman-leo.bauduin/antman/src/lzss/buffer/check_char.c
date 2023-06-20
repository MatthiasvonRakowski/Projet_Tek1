/*
** EPITECH PROJECT, 2023
** antman
** File description:
** check_char
*/

#include "antman.h"

int check_char(lz_t *lz)
{
    lz->dico[0] = lz->buff[0];
    lz->buff_pos = 1;
    write_one_char(lz->buff[0], lz);
    for ( ; lz->buff_pos < lz->st.st_size; lz->buff_pos++) {
        analyse_buffer(lz->buff[lz->buff_pos], lz);
    }
    return 0;
}
