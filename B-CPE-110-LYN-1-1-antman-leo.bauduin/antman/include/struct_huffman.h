/*
** EPITECH PROJECT, 2023
** antman/include/struct_huffman
** File description:
** csfml is the best thing ever
*/

#ifndef STRUCT_HUFFMAN
    #define STRUCT_HUFFMAN

/*-----------------------------------STRUCT-----------------------------------*/

typedef struct huffman_st_s {
    int nbr;
    int binary;
    char value;
    struct huffman_st_s *right;
    struct huffman_st_s *left;
    struct huffman_st_s *prev;
    struct huffman_st_s *next;
} huffman_st_t;

typedef struct last_str_s {
    int size;
    char **letters_bits;
    int place;
    int letter;
    int nb_letter;
    int pos_bit;
    int new_letter;
    char *new_str;
} last_str_t;

/*---------------------------------PROGRAMM-----------------------------------*/

huffman_st_t *binary_tree(huffman_st_t *huffman, int a);
huffman_st_t *bubble_sort(huffman_st_t *ele, int nb_char);
huffman_st_t *node_for_char(char c, huffman_st_t *huffman, int *i);
huffman_st_t *creat_node_huffman(char c, huffman_st_t *list);
huffman_st_t *place_new_huff(huffman_st_t *new_huff, huffman_st_t *huffman);
char *find_letter_and_bit(huffman_st_t *huffman);
char *huffman_str(huffman_st_t *huffman, char *buff, int nbr_char, int *size);
#endif
