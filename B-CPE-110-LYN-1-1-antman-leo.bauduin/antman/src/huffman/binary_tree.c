/*
** EPITECH PROJECT, 2023
** antman
** File description:
** binary_tree
*/

#include "antman.h"

void put_last(huffman_st_t *new_huff, huffman_st_t *huffman)
{
    new_huff->next = NULL;
    new_huff->prev = huffman;
    new_huff->prev->next = new_huff;
}

huffman_st_t *find_the_place(huffman_st_t *huffman, huffman_st_t **temp_2,
huffman_st_t *new_huff)
{
    while (huffman && huffman->nbr < new_huff->nbr) {
        if (!(huffman->next)) {
            *temp_2 = huffman;
        }
        huffman = huffman->next;
    }
    return huffman;
}

huffman_st_t *place_new_huff(huffman_st_t *new_huff, huffman_st_t *huffman)
{
    huffman_st_t *temp = huffman;
    huffman_st_t *temp_2 = NULL;

    if (!(huffman))
        return new_huff;
    huffman = find_the_place(huffman, &temp_2, new_huff);
    if (temp_2) {
        put_last(new_huff, temp_2);
        return temp;
    }
    if (huffman->prev == new_huff)
        return new_huff;
    temp->prev = NULL;
    new_huff->prev = huffman->prev;
    new_huff->next = huffman;
    huffman->prev->next = new_huff;
    huffman->prev = new_huff;
    return temp;
}

huffman_st_t *init_new_huff(huffman_st_t *huffman)
{
    huffman_st_t *new_huff;

    new_huff = creat_node_huffman(0, huffman);
    new_huff->left = new_huff->next;
    new_huff->right = new_huff->next->next;
    new_huff->right->next = NULL;
    new_huff->right->prev = new_huff;
    new_huff->right->binary = 1;
    new_huff->left->prev = new_huff;
    new_huff->left->next = NULL;
    new_huff->nbr = new_huff->right->nbr + new_huff->left->nbr;
    return new_huff;
}

huffman_st_t *binary_tree(huffman_st_t *huffman, int a)
{
    huffman_st_t *new_huff;
    huffman_st_t *temp;

    if (!(huffman->next))
        return huffman;
    temp = huffman->next->next;
    new_huff = init_new_huff(huffman);
    new_huff->next = temp;
    if (temp)
        temp->prev = new_huff;
    new_huff = place_new_huff(new_huff, new_huff->next);
    new_huff = binary_tree(new_huff, a);
    return new_huff;
}
