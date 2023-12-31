/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** a short file description
*/

#include "op.h"

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 0, 1},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 0, 1},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 0, 1},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 0, 1},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "et (and  r1, r2, r3   r1&r2 -> r3", 0, 1},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "ou  (or   r1, r2, r3   r1 | r2 -> r3", 0, 1},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3", 0, 1},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 1, 0},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index", 1, 1},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index", 1, 1},
    {"fork", 1, {T_DIR}, 12, 800, "fork", 1, 0},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 0, 1},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index", 1, 1},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 1, 0},
    {"aff", 1, {T_REG}, 16, 2, "aff", 0, 1},
    {0, 0, {0}, 0, 1, 0, 0, 0}
};
