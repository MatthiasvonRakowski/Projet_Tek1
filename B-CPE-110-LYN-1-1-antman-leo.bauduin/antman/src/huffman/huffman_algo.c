/*
** EPITECH PROJECT, 2023
** antman/huffman_algo
** File description:
** huffman algo
*/

#include "antman.h"

char *huffman_algo(char *buffer, int *size)
{
    huffman_st_t *huffman = NULL;
    int nb_char = 0;
    char *new_str;

    for (int i = 0; buffer[i] != '\0'; i++) {
        huffman = node_for_char(buffer[i], huffman, &nb_char);
    }
    huffman = bubble_sort(huffman, nb_char);
    huffman = binary_tree(huffman, nb_char);
    new_str = huffman_str(huffman, buffer, nb_char, size);
    return new_str;
}
