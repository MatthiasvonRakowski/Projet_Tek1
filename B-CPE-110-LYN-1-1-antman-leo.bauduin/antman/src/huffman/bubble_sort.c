/*
** EPITECH PROJECT, 2023
** antman/merge_sort
** File description:
** merge sort
*/

#include "antman.h"

huffman_st_t *comp_huff_size(huffman_st_t *ele)
{
    int temp_int;
    char temp_char;

    if (!(ele->next))
        return ele;
    if (ele->nbr > ele->next->nbr) {
        temp_int = ele->nbr;
        temp_char = ele->value;
        ele->nbr = ele->next->nbr;
        ele->next->nbr = temp_int;
        ele->value = ele->next->value;
        ele->next->value = temp_char;
    }
    ele = ele->next;
    return ele;
}

huffman_st_t *bubble_sort(huffman_st_t *ele, int nb_char)
{
    huffman_st_t *temp = ele;

    for (; nb_char > 1; nb_char--) {
        for (int i = 0; i < nb_char - 1; i++) {
            ele = comp_huff_size(ele);
        }
        ele = temp;
    }
    return temp;
}
