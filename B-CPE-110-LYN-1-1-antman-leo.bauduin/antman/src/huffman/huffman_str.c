/*
** EPITECH PROJECT, 2023
** huffman_str
** File description:
** change str in an huffman str
*/

#include "antman.h"
#include <malloc.h>
#include <stdio.h>

char **letter_bit(huffman_st_t *huffman, int nb_char)
{
    void *temp = huffman;
    char **arr = malloc(sizeof(int*) * (nb_char + 1));
    int i = 0;

    for (; i < nb_char; i++) {
        arr[i] = find_letter_and_bit(huffman);
        huffman = temp;
    }
    arr[i] = NULL;
    return arr;
}

void creat_letter(last_str_t *last_str)
{
    int size = last_str->letters_bits[last_str->letter][1];

    last_str->pos_bit = 2;
    while (size != 0) {
        if (last_str->place == 0) {
            last_str->new_letter++;
            last_str->new_str[last_str->new_letter] = 0;
        }
        for (;size != 0 && last_str->place < 8; last_str->place++,
            last_str->pos_bit++, size--) {
            last_str->new_str[last_str->new_letter] <<= 1;
            last_str->new_str[last_str->new_letter] |=
            last_str->letters_bits[last_str->letter][last_str->pos_bit] - '0';
        }
        if (last_str->place == 8) {
            last_str->nb_letter++;
            last_str->place = 0;
        }
    }
}

last_str_t *init_last_str(huffman_st_t *huffman, int nbr_char)
{
    last_str_t *ele = malloc(sizeof(last_str_t));

    ele->letters_bits = letter_bit(huffman, nbr_char);
    ele->size = nbr_char - 1;
    ele->new_str = malloc(sizeof(char) * 10000000);
    ele->place = 0;
    ele->letter = 0;
    ele->pos_bit = 0;
    ele->new_letter = 2;
    return ele;
}

void get_tree(last_str_t *last_str)
{
    last_str->new_str[0] = last_str->size;
    for (int i = 0; last_str->letters_bits[i] != NULL; i++) {
        for (int j = 0; j < 2; j++) {
            last_str->new_str[last_str->new_letter] =
            last_str->letters_bits[i][j];
            last_str->new_letter++;
        }
    }
}

char *huffman_str(huffman_st_t *huffman, char *buff, int nbr_char, int *size)
{
    last_str_t *last_str = init_last_str(huffman, nbr_char);
    char last_bitwise = 0;

    get_tree(last_str);
    for (int i = 0; buff[i] != '\0'; i++) {
        for (last_str->letter = 0;
        last_str->letters_bits[last_str->letter][0] !=
        buff[i]; last_str->letter++);
        creat_letter(last_str);
    }
    free(buff);
    for (int i = last_str->place; i < 8 ; i++, last_bitwise++) {
        last_str->new_str[last_str->new_letter] <<= 1;
    }
    last_str->new_str[1] = last_bitwise;
    *size = last_str->new_letter + 1;
    last_str->new_str[last_str->new_letter + 1] = '\0';
    return last_str->new_str;
}
