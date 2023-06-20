/*
** EPITECH PROJECT, 2023
** src/generator_manager
** File description:
** generator manager
*/

#include "generator.h"

char fill_maze(int **arr, int i, int j)
{
    if (arr[i][j] != -1) {
        return '*';
    } else {
        return 'X';
    }
}

void print_maze(int **arr, int *dimension)
{
    char *maze = malloc(sizeof(char) * dimension[1] * (dimension[0] + 1) + 1);
    int place = 0;

    for (int i = 0; i < dimension[1]; i++, place++) {
        for (int j = 0; j < dimension[0]; j++, place++) {
            maze[place] = fill_maze(arr, i, j);
        }
        free(arr[i]);
        maze[place] = '\n';
    }
    free(arr);
    maze[place - 1] = '\0';
    write(1, maze, dimension[1] * (dimension[0] + 1) - 1);
    free(maze);
}

int generator_perfect(int x, int y)
{
    int dimension[2] = {x, y};
    int size_indic = (dimension[1] * dimension[0]) / 2;
    int **indic = malloc(sizeof(int *) * size_indic);
    int **arr = map_malloc(dimension, &indic);

    indic = shuffle_list(indic, size_indic);
    create_maze(arr, dimension, indic);
    print_maze(arr, dimension);
    return 0;
}

void transform_perfect_in_imperfect(int **arr, int *dim)
{
    if (dim[0] >= 3 && dim[1] >= 3) {
        arr[0][1] = 0;
        arr[1][0] = 0;
        arr[1][2] = 0;
        arr[2][1] = 0;
    }
}

int generator_imperfect(int x, int y)
{
    int dimension[2] = {x, y};
    int size_indic = (dimension[1] * dimension[0]) / 2;
    int **indic = malloc(sizeof(int *) * size_indic);
    int **arr = map_malloc(dimension, &indic);

    indic = shuffle_list(indic, size_indic);
    create_maze(arr, dimension, indic);
    transform_perfect_in_imperfect(arr, dimension);
    print_maze(arr, dimension);
    return 0;
}
