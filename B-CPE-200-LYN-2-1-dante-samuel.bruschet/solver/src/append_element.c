/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-quentin.cialone
** File description:
** add_element.c
*/

#include "../include/my.h"

void append_sorted(struct maze *c, struct head **openlist)
{
    struct op_list *to_insert = malloc(sizeof(struct op_list));
    struct op_list *current = (*openlist)->head;

    c->open = 1;
    to_insert->act = c;
    to_insert->next = NULL;
    if ((*openlist)->head == NULL ||
        to_insert->act->f < (*openlist)->head->act->f) {
        to_insert->next = (*openlist)->head;
        (*openlist)->head = to_insert;
    } else {
        while (current->next != NULL &&
            current->next->act->f <= to_insert->act->f)
            current = current->next;
        to_insert->next = current->next;
        current->next = to_insert;
    }
}

void append_element(struct maze *c, struct head **openlist)
{
    struct op_list *new_head = malloc(sizeof(*new_head));

    new_head->act = c;
    new_head->next = (*openlist)->head;
    (*openlist)->head = new_head;
}
