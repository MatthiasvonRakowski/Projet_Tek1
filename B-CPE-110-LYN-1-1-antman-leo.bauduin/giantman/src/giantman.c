/*
** EPITECH PROJECT, 2022
** main du BG
** File description:
** main hello
*/

#include "giantman.h"
#include <stdio.h>

int giantman(char *filepath)
{
    int fd;
    int size_writer;
    struct stat st;
    char *buffer;
    char *new_buff;

    if ((fd = open(filepath, O_RDONLY)) < 0) {
        close(fd);
        my_putstr("The file doesn't exist or can't open");
        return 84;
    }
    stat(filepath, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buffer, st.st_size);
    if (buffer[st.st_size - 1] == (char) 8) {
        buffer[st.st_size - 1] = '\0';
        size_writer = st.st_size;
        close (fd);
        new_buff = huff_decomp(buffer, &size_writer);
        write(1, new_buff, size_writer);
    }
    return 0;
}
