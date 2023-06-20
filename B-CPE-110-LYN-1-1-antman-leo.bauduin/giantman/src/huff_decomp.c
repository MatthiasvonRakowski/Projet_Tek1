/*
** EPITECH PROJECT, 2023
** src/huff_decomp
** File description:
** decompression for huffman
*/

#include "giantman.h"

void new_letter(decomp_t *decomp)
{

    if (decomp->bit) {
        decomp->huff = decomp->huff->right;
    } else {
        decomp->huff = decomp->huff->left;
    }
    if (decomp->huff->value != 0) {
        decomp->str[decomp->pos] = decomp->huff->value;
        decomp->pos++;
        decomp->huff = decomp->temp;
    }
}

decomp_t *init_decomp(huff_t *huff)
{
    decomp_t *decomp = malloc(sizeof(decomp_t));

    decomp->str = malloc(sizeof(char) * 100000000);
    decomp->temp = huff;
    decomp->bit = 0;
    decomp->pos = 0;
    decomp->huff = huff;
    return decomp;
}

char *decomp_str(huff_t *huff, char *buffer, int *size)
{
    decomp_t *decomp = init_decomp(huff);

    for (int i = (unsigned char) ((buffer[0] + 2) * 2 + 1); i < (*size) - 1;
        i++) {
        for (int j = 0; j < 8; j++) {
            decomp->bit = buffer[i] << j;
            decomp->bit >>= 7;
            new_letter(decomp);
        }
    }
    for (int j = 0; j < 8 - buffer[1]; j++) {
        decomp->bit = buffer[(*size) - 1] << j;
        decomp->bit >>= 7;
        new_letter(decomp);
    }
    (*size) = decomp->pos;
    return decomp->str;
}

char *huff_decomp(char *buffer, int *size)
{
    huff_t *huff = construct_tree(buffer);
    char *str = decomp_str(huff, buffer, size);

    return str;
}
