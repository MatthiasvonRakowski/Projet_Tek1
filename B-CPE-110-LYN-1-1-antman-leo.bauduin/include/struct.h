/*
** EPITECH PROJECT, 2023
** struct
** File description:
** the antman struct
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct huffman_s {
    int nbr;
    int binaire;
    char value;
    struct huffman_s *right;
    struct huffman_s *left;
    struct huffman_s *prev;
} huffman_t;

#endif
