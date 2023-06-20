/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-quentin.cialone
** File description:
** add_element.c
*/

#include "../include/my.h"

void print_list(struct head *oplist)
{
    struct op_list *ptr = oplist->head;

    printf("-------------\n");
    while (ptr != NULL) {
        printf("%d %d\n", ptr->act->i, ptr->act->j);
        ptr = ptr->next;
    }
    printf("-------------\n\n");
}
