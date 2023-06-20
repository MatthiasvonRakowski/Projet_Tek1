/*
** EPITECH PROJECT, 2023
** tests/test_huff_bits
** File description:
** testes on the bits part
*/


#include "antman.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(find_letter_and_bit, test_function_find_bit, .init = redirect_all_stdout) {
    huffman_st_t *huffman = NULL;
    char str[] = "je m'appelle von Rakowski";
    int a = 0;
    int *arr;
    char no[] = "m";

    for (int i = 0; str[i] != '\0'; i++) {
        huffman = node_for_char(str[i], huffman, &a);
    }
    huffman = bubble_sort(huffman, a);
    huffman = binary_tree(huffman, a);
    arr = find_letter_and_bit(huffman);
    no[0] = arr[2] + '0';
    write(1, "4", 1);
    cr_assert_stdout_eq_str(no, "");
}
