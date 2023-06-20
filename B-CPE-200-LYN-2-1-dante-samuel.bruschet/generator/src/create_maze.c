/*
** EPITECH PROJECT, 2023
** src/create_maze
** File description:
** maze creator
*/

#include "generator.h"

void x_modifier(int **arr, int x, int y, int *dim)
{
    if (x != dim[0] - 1) {
        if (arr[y][x + 1] < arr[y][x - 1]) {
            arr[y][x] = -2;
            modify_arr(arr, x, y,
                (int[3]) {dim[0], dim[1], arr[y][x + 1]});
        }
        if (arr[y][x + 1] > arr[y][x - 1]) {
            arr[y][x] = -2;
            modify_arr(arr, x, y,
                (int[3]) {dim[0], dim[1], arr[y][x - 1]});
        }
    } else
        arr[y][x] = arr[y][x - 1];
}

void y_modifier(int **arr, int x, int y, int *dim)
{
    if (y != dim[1] - 1) {
        if (arr[y + 1][x] < arr[y - 1][x]) {
            arr[y][x] = -2;
            modify_arr(arr, x, y,
                (int[3]) {dim[0], dim[1], arr[y + 1][x]});
        }
        if (arr[y + 1][x] > arr[y - 1][x]) {
            arr[y][x] = -2;
            modify_arr(arr, x, y,
                (int[3]) {dim[0], dim[1], arr[y - 1][x]});
        }
    } else
        arr[y][x] = arr[y - 1][x];
}

void create_maze(int **arr, int *dim, int **indic)
{
    int nbr_change = (dim[1] * dim[0]) / 2;
    int x;
    int y;

    srand(time(NULL));
    for (int i = 0; i < nbr_change; i++) {
        x = indic[i][0];
        y = indic[i][1];
        if (x % 2 != 0) {
            x_modifier(arr, x, y, dim);
        } else {
            y_modifier(arr, x, y, dim);
        }
        free(indic[i]);
    }
    free(indic);
    if (dim[0] % 2 == 0 && dim[1] % 2 == 0) {
        arr[dim[1] - 1][dim[0] - 1] = 0;
        arr[dim[1] - 2][dim[0] - 1] = -1;
    }
}
