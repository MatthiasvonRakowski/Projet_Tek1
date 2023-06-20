/*
** EPITECH PROJECT, 2023
** antman
** File description:
** analyse_buffer
*/

#include "antman.h"

void add_char_dico(char c, lz_t *lz)
{
    lz->dico[lz->dico_pos++] = c;
    lz->dico[lz->dico_pos] = '\0';

}

void analyse_buffer(char c, lz_t *lz)
{
    int s_dico = lz->dico_pos, c_tmp = 0;
    char *str;

    for (; lz->dico[s_dico] != c && s_dico > 0; s_dico -= 1);
    str = malloc(sizeof(char) * 16);

    while (lz->dico[s_dico++] == (c = lz->buff[lz->buff_pos]) && c_tmp <= 15) {
        add_char_dico(c, lz);
        str[c_tmp++] = lz->buff[lz->buff_pos++];
    }
    if (c_tmp > 2)
        write_coord_buff(s_dico, c_tmp, lz);
    else
        write_one_char(c, lz);
    free(str);
}
