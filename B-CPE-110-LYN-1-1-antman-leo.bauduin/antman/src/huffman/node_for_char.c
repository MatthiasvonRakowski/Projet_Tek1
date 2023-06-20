/*
** EPITECH PROJECT, 2023
** node_for_char
** File description:
** you're a bad developer
*/

#include "antman.h"

huffman_st_t *node_for_char(char c, huffman_st_t *huffman, int *nb_char)
{
    huffman_st_t *temp = huffman;

    while (huffman) {
        if (huffman->value == c) {
            huffman->nbr++;
            return temp;
        }
        huffman = huffman->next;
    }
    (*nb_char)++;
    return creat_node_huffman(c, temp);
}
