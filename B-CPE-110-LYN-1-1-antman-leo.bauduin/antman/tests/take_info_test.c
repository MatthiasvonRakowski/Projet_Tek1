/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** take_info_test
*/

#include "antman.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (node_for_char, test_function_node_char, .init = redirect_all_stdout) {
    char *str = "aaaaaaaaaaaaaaab";
    char str2[] = "abaa";
    int a = 0;
    huffman_st_t *huffman = NULL;

    str2[0] = 1;
    str2[2] = 15;
    for (int i = 0; str[i] != '\0'; i++) {
        huffman = node_for_char(str[i], huffman, &a);
    }
    while (huffman) {
        write(1, &huffman->nbr, 1);
        write(1, &huffman->value, 1);
        huffman = huffman->next;
    }
    cr_assert_stdout_eq_str(str2, "");
}

Test (bubble_sort, test_function_bubble_sort, .init = redirect_all_stdout) {
    huffman_st_t *huffman = NULL;
    int a = 0;
    char str[] = "Je m'appelle matthias";
    char nbr;

    for (int i = 0; str[i] != '\0'; i++) {
        huffman = node_for_char(str[i], huffman, &a);
    }
    huffman = bubble_sort(huffman, a);
    while (huffman) {
        nbr = huffman->nbr + '0';
        write(1, &nbr, 1);
        write(1, &huffman->value, 1);/**/
        huffman = huffman->next;
    }
    cr_assert_stdout_eq_str("1s1i1h1'1J2t2l2p2m2 3a3e", "");
}

Test (place_new_huff, test_function_place_new_hu, .init = redirect_all_stdout) {
    huffman_st_t *huffman = NULL;
    int a = 0;
    char str[] = "JJeeiaaaJJ";

    for (int i = 0; str[i] != '\0'; i++) {
        huffman = node_for_char(str[i], huffman, &a);
    }
    huffman = place_new_huff(huffman, huffman->next);
    while (huffman) {
        write(1, &huffman->value, 1);
        huffman = huffman->next;
    }
    cr_assert_stdout_eq_str("ieaJ", "");
}

Test (binary_tree, test_function_binarry_tree, .init = redirect_all_stdout) {
    huffman_st_t *huffman = NULL;
    char str[] = "je m'appelle von Rakowski";
    int a = 0;
    char str_try[] = "z";
    char c = 25;

    for (int i = 0; str[i] != '\0'; i++) {
        huffman = node_for_char(str[i], huffman, &a);
    }
    huffman = bubble_sort(huffman, a);
    huffman = binary_tree(huffman, a);
    write(1, &c, 1);
    str_try[0] = huffman->nbr;
    cr_assert_stdout_eq_str(str_try, "");
}
