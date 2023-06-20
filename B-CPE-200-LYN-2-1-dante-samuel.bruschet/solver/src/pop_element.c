/*
** EPITECH PROJECT, 2023
** src/generator_manager
** File description:
** get_maze
*/

#include "../include/my.h"

struct op_list *pop_element(struct head **openlist)
{
    struct op_list *save_ptr;

    save_ptr = (*openlist)->head;
    (*openlist)->head = save_ptr->next;
    save_ptr->act->open = 2;
    return save_ptr;
}
