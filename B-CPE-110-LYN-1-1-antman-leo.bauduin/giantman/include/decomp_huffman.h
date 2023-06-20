/*
** EPITECH PROJECT, 2023
** giantman/include/decomp_huffman
** File description:
** include of decomp_huffman
*/

#ifndef DECOMP_HUFFMAN_H
    #define DECOMP_HUFFMAN_H

typedef struct huff_s {
    char value;
    int close;
    struct huff_s *prev;
    struct huff_s *right;
    struct huff_s *left;
} huff_t;

typedef struct decomp_s {
    char *str;
    void *temp;
    unsigned char bit;
    int pos;
    huff_t *huff;
} decomp_t;

/*--------------------------------PROGRAMME-----------------------------------*/

char *huff_decomp(char* buffer, int *size_writer);
huff_t *construct_tree(char *buffer);

#endif
