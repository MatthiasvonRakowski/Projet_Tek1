/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-quentin.cialone
** File description:
** add_element.c
*/
#include "../include/my.h"

void apply_a_star(struct global **global, struct op_list *current,
            int i, int j)
{
    int heuristic;
    int tempG;
    struct maze *neighbor = &(*global)->s_maze[i][j];

    if (i < 0 || i >= (*global)->x || j < 0 || j >= (*global)->y)
        return;
    if (neighbor->open == 2 || neighbor->c == 'X')
        return;
    tempG = current->act->g + 1;
    if (neighbor->open == 1) {
        if (tempG >= neighbor->g)
            return;
    }
    neighbor->open = 1;
    neighbor->g = tempG;
    neighbor->parent = current->act;
    heuristic = ((*global)->x - i) * ((*global)->x - i) +
            ((*global)->y - j) + ((*global)->y - j);
    neighbor->f = neighbor->g + heuristic;
    append_sorted(neighbor, (*global)->oplist);
}
