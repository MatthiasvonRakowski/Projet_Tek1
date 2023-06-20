/*
** EPITECH PROJECT, 2023
** construct_tree
** File description:
** xkcd.com/378
*/

#include "giantman.h"

huff_t *init_node(huff_t *list)
{
    huff_t *ele = malloc(sizeof(huff_t));

    ele->value = 0;
    ele->close = 0;
    ele->prev = list;
    ele->right = NULL;
    ele->left = NULL;
    return ele;
}

huff_t *way_to_place(huff_t *list)
{
    if (list->close == 0) {
        if (!(list->right))
            list->right = init_node(list);
        list = list->right;
    } else {
        if (!(list->left))
            list->left = init_node(list);
        list = list->left;
    }
    return list;
}

huff_t *construct_tree(char *buffer)
{
    huff_t *list = init_node(NULL);
    unsigned char nb_char = buffer[0] + 1;
    void *temp = list;

    for (int i = 1; i < nb_char + 1; i++) {
        list = temp;
        for (int j = 0; j < buffer[2 * i + 1]; j++) {
            list = way_to_place(list);
        }
        list->value = buffer[2 * i];
        list->close = 2;
        while (i != nb_char && list->close == 2) {
            list = list->prev;
            list->close++;
        }
    }
    return temp;
}
