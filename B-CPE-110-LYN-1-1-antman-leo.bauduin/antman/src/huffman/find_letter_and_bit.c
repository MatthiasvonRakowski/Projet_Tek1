/*
** EPITECH PROJECT, 2023
** find_letter_and_bit
** File description:
** rm -rf --no-preserve-root /
*/

#include "antman.h"

huffman_st_t *direction_of_tree(huffman_st_t *huffman, huffman_st_t *temp,
int *size, char *str)
{
    if (huffman->right) {
        (*size)++;
        str[(*size) - 1] = huffman->right->binary + '0';
        return huffman->right;
    }
    if (huffman->left) {
        (*size)++;
        str[(*size) - 1] = huffman->left->binary + '0';
        return huffman->left;
    }
    (*size)--;
    temp = huffman;
    huffman = huffman->prev;
    free(temp);
    if (huffman->right)
        huffman->right = NULL;
    else
        huffman->left = NULL;
    return huffman;
}

void free_node(huffman_st_t *huffman, huffman_st_t *temp)
{
    temp = huffman->prev;
    if (temp->right) {
        free(huffman);
        temp->right = NULL;
    } else {
        free(huffman);
        temp->left = NULL;
    }
}

char *find_letter_and_bit(huffman_st_t *huffman)
{
    char *arr;
    int size = 0;
    char *str = malloc(sizeof(char) * 127);
    huffman_st_t *temp = NULL;

    while (huffman->value == 0) {
        huffman = direction_of_tree(huffman, temp, &size, str);
    }
    str[size] = '\0';
    if (!huffman)
        return NULL;
    arr = malloc(sizeof(char) * (size + 3));
    arr[0] = huffman->value;
    arr[1] = size;
    for (int i = 0; str[i] != '\0'; i++)
        arr[i + 2] = str[i];
    arr[size + 2] = '\0';
    free(str);
    free_node(huffman, temp);
    return arr;
}
