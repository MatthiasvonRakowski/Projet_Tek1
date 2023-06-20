/*
** EPITECH PROJECT, 2023
** src/generator_perfect
** File description:
** make a perfect maze
*/

#include "generator.h"

int **shuffle_list (int **indic, int size)
{
    int *temp;
    int new_place = 0;

    srand(time(NULL));
    for (int i = 0; i < size - 1; i++) {
        new_place = rand() % (size - i) + i;
        temp = indic[i];
        indic[i] = indic[new_place];
        indic[new_place] = temp;
    }
    return indic;
}

int fill_arrays(int pos[2], int ***indic, int *indic_nbr, int nbr)
{
    int **new_indic = *indic;

    if (pos[1] % 2 != 0 || pos[0] % 2 != 0) {
        if (pos[1] % 2 == 0 || pos[0] % 2 == 0) {
            new_indic[*indic_nbr] = malloc(sizeof(int) * 2);
            new_indic[*indic_nbr][0] = pos[0];
            new_indic[*indic_nbr][1] = pos[1];
            *indic_nbr += 1;
            *indic = new_indic;
        }
        return -1;
    } else {
        return nbr / 2;
    }
}

int **map_malloc(int *dimension, int ***indic)
{
    int **arr = malloc(sizeof(int *) * (dimension[1]));
    int nbr = 0;
    int **new_indic = *indic;
    int indic_nbr = 0;

    for (int i = 0; i < dimension[1]; i++) {
        arr[i] = malloc(sizeof(int) * (dimension[0]));
        for (int j = 0; j < dimension[0]; j++, nbr++) {
            arr[i][j] = fill_arrays((int[2]) {j, i}, &new_indic,
            &indic_nbr, nbr);
        }
    }
    *indic = new_indic;
    return arr;
}

void modify_arr(int **arr, int x, int y, int data[3])
{
    if (arr[y][x] != -1 && arr[y][x] != data[2])
        arr[y][x] = data[2];
    else
        return;
    if (x - 1 >= 0)
        modify_arr(arr, x - 1, y, data);
    if (y < data[1] - 1)
        modify_arr(arr, x, y + 1, data);
    if (y - 1 >= 0)
        modify_arr(arr, x, y - 1, data);
    if (x < data[0] - 1)
        modify_arr(arr, x + 1, y, data);
    return;
}
