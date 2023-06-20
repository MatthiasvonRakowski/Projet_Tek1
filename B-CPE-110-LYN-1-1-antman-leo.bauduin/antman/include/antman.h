/*
** EPITECH PROJECT, 2023
** antman
** File description:
** antman
*/


#ifndef ANTMAN_H
    #define ANTMAN_H
    #include <malloc.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include "struct_lzss.h"
    #include "struct_huffman.h"

typedef struct prog_s {
    int size;
    char *buf;
} prog_t;

/*--------------------------------PROGRAMME----------------------------------*/
int antman(char *filepath);
void my_putstr(char const *str);
char *huffman_algo(char *buffer, int *size);
int choose_algo(char *buf, struct stat st);

#endif //ANTMAN_H
