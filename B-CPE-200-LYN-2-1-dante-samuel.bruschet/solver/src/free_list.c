/*
** EPITECH PROJECT, 2023
** src/generator_manager
** File description:
** valid expression
*/

#include "../include/my.h"

void free_list(struct head **oplist)
{
    struct op_list *head = (*oplist)->head;
    struct op_list *save = NULL;

    while (head != NULL) {
        save = head->next;
        free(head);
        head = save;
    }
    free(*oplist);
}
