/*
** EPITECH PROJECT, 2022
** my_delete_nodes
** File description:
** delet all equal nodes to the ref data
*/

#include "include/my.h"

void temp_freeer(filename_t *prev, filename_t *actual, void const *data_ref)
{
    filename_t *tmp;

    if (my_strcmp(actual->name, data_ref) != 0) {
        prev->next = actual->next;
        tmp = actual;
        actual = actual->next;
        free(tmp);
    } else {
        prev = prev->next;
        actual = actual->next;
        }
}

int my_delete_nodes(filename_t **begin, void const *data_ref)
{
    filename_t *prev;
    filename_t *actual = *begin;
    filename_t *head;

    while (actual != NULL && my_strcmp(actual->name, data_ref) != 0) {
        prev = actual->next;
        free(actual);
        actual = prev;
    }
    head = actual;
    prev = actual;
    if (actual)
        actual = actual->next;
    while (actual != NULL) {
        temp_freeer(prev, actual, data_ref);
    }
    *begin = head;
    return 0;
}
