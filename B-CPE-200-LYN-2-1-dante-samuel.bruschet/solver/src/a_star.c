/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-quentin.cialone
** File description:
** add_element.c
*/

#include "../include/my.h"

void a_star(struct global **global, char **maze)
{
    struct op_list *act;

    while ((*((*global)->oplist))->head != NULL) {
        act = pop_element((*global)->oplist);
        if (act->act->i == (*global)->x - 1 && act->act->j == (*global)->y - 1)
            break;
        apply_a_star(global, act, act->act->i + 1, act->act->j);
        apply_a_star(global, act, act->act->i - 1, act->act->j);
        apply_a_star(global, act, act->act->i, act->act->j - 1);
        apply_a_star(global, act, act->act->i, act->act->j + 1);
        free(act);
    }
    if ((*global)->s_maze[(*global)->x - 1][(*global)->y - 1].open == 2)
        victoire(*global, maze);
    else
        printf("no solution found");
}
