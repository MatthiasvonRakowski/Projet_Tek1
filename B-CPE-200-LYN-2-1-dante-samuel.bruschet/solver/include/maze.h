/*
** EPITECH PROJECT, 2023
** src/generator_perfect
** File description:
** make a perfect maze
*/

#ifndef B_CPE_200_LYN_2_1_DANTE_SAMUEL_BRUSCHET_MAZE_H
    #define B_CPE_200_LYN_2_1_DANTE_SAMUEL_BRUSCHET_MAZE_H

struct maze {
    short i;
    short j;
    int f;
    int g;
    char c;
    char open;
    struct maze *parent;
};

struct global {
    int x;
    int y;
    struct maze **s_maze;
    struct head **oplist;
};

struct op_list {
    struct maze *act;
    struct op_list *next;
};

struct head {
    struct op_list *head;
};

#endif //B_CPE_200_LYN_2_1_DANTE_SAMUEL_BRUSCHET_MAZE_H
