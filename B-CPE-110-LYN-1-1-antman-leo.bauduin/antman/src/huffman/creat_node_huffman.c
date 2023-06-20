/*
** EPITECH PROJECT, 2023
** creat_node_huffman
** File description:
** Create a node for huffman list
*/

#include "antman.h"

huffman_st_t *creat_node_huffman(char c, huffman_st_t *list)
{
    huffman_st_t *huffman = malloc(sizeof(huffman_st_t));

    huffman->value = c;
    huffman->nbr = 1;
    huffman->binary = 0;
    huffman->left = NULL;
    huffman->right = NULL;
    huffman->prev = NULL;
    huffman->next = list;
    if (!(list))
        return huffman;
    list->prev = huffman;
    return huffman;
}
