/*
** EPITECH PROJECT, 2023
** antman
** File description:
** antman
*/

#include "antman.h"

void init_lz(lz_t *lz, char *buff, struct stat st)
{
    lz->st = st;
    lz->buff = buff;
    lz->buff_pos = 0;
    lz->dico_pos = 0;
    lz->pos_f_buff = 0;
    lz->dico = malloc(sizeof(char) * DICO_SIZE);
    lz->final_str = malloc(sizeof(char) * st.st_size);
}

int antman(char *filepath)
{
    int fd;
    int size_writer;
    struct stat st;
    lz_t *lz = malloc(sizeof(lz_t));
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
    buffer[st.st_size] = '\0';
    close (fd);
    new_buff = huffman_algo(buffer, &size_writer);
    new_buff[size_writer] = (char) 8;
    write(1, new_buff, size_writer + 1);
    return 0;
}
