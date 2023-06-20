/*
** EPITECH PROJECT, 2022
** bsq.c
** File description:
** bsq
*/

#include "mylib/include/my.h"

int solucer_i(char **arr, coor_t *pos, short **nb_arr)
{
    for (short i = pos->nbr - 1; i >= 0; i--)
        for (short k = pos->nbr - 1; k >= 0; k--)
            arr[pos->mem_x - i][pos->mem_y - k] = 'x';
    for (short i = 0; i < pos->size; i++) {
        write(1, arr[i], pos->size_str + 1);
        free(arr[i]);
        free(nb_arr[i]);
    }
    free(arr);
    free(nb_arr);
    return 0;
}

int temp_coding_style(short **nb_arr, char **arr, char *buffer, coor_t *pos)
{
    int secure = 0;

    for (; buffer[pos->k]; pos->y++, pos->k++) {
        if (((buffer[pos->k] == '\n' || buffer[pos->k] == '\0') &&
            pos->y != pos->size_str) || (buffer[pos->k] == '\0' &&
            pos->x != pos->size))
            return 84;
        if (buffer[pos->k] != '\n') {
            secure = point_or_nbr(nb_arr, arr, buffer[pos->k], pos);
        } else {
            reinit(arr, pos);
            nb_arr[pos->x] = malloc(sizeof(short) * pos->size_str);
            arr[pos->x] = malloc(sizeof(char) * (pos->size_str + 2));
        }
    }
        if (secure == 84)
            return 84;
    return 0;
}

int creat_map(int size, char *str)
{
    short **nb_arr = malloc(sizeof(short *) * size);
    char **arr = malloc(sizeof(char *) * size);
    coor_t *pos = malloc(sizeof(coor_t));
    int secure = 0;

    init(pos);
    pos->t_size = my_strlen(str);
    pos->size = size;
    pos->size_str = size;
    for (; pos->x < size; pos->x++) {
        arr[pos->x] = malloc(sizeof(char) * size + 2);
        nb_arr[pos->x] = malloc(sizeof(short) * size);
        secure = create_conding_style(str, nb_arr, arr, pos);
        if (secure == 84)
            return 84;
        arr[pos->x][pos->size_str] = '\n';
        arr[pos->x][pos->size_str + 1] = '\0';
    }
    return solucer_i(arr, pos, nb_arr);
}

int get_map(int fd, char *filename)
{
    struct stat stats;
    coor_t *pos = malloc(sizeof(coor_t));
    int secure = 0;
    init(pos);
    stat(filename, &stats);
    char *buffer = malloc(sizeof(char) * stats.st_size);
    read(fd, buffer, stats.st_size);
    pos->size = my_getnbr(buffer, pos);
    short **nb_arr = malloc(sizeof(short *) * pos->size);
    char **arr = malloc(sizeof(char *) * pos->size);
    for (int n = ++pos->k; buffer[n] != '\n'; n++, pos->size_str++);
    nb_arr[0] = malloc(sizeof(short) * pos->size_str);
    arr[0] = malloc(sizeof(char) * (pos->size_str + 2));
    secure = temp_coding_style(nb_arr, arr, buffer, pos);
    if (secure == 84)
        return 84;
    return solucer_i(arr, pos, nb_arr);
}

int main(int ac, char **av)
{
    int fd;
    int secure = 0;

    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        if (fd < 1) {
            close(fd);
            return 84;
        }
        secure = get_map(fd, av[1]);
        close(fd);
    } else
        secure = creat_map(my_getnbr_rec(av[1]), av[2]);
    return secure;
}
