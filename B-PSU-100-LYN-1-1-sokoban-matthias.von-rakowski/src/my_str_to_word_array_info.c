/*
** EPITECH PROJECT, 2022
** my_str_to_word_array_info
** File description:
** hey. real programmers use vim
*/

#include "../include/my.h"

void creation_of_array(char **arr, char *map, int *size, int *size_str)
{
    int j = 0;
    int k = 0;
    int temp = 0;

    while (k < (*size) - 1) {
        if (map[j] == '\n')
            j++;
        for (temp = 0; map[j] != '\n'; temp++, j++);
        arr[k] = malloc(sizeof(char) * temp + 1);
        for (j = j - temp, temp = 0; map[j] != '\n'; temp++, j++)
            arr[k][temp] = map[j];
        arr[k][temp] = '\0';
        k++;
        if ((*size_str) < temp)
            *size_str = temp;
    }
}

char **my_str_to_word_array_info(char *map, int *size, int *size_str)
{
    char **arr;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != ' ' && map[i] != '\n' && map[i] != '#' && map[i] != 'O' &&
            map[i] != 'X' && map[i] != 'P')
            exit(84);
        if (map[i] == '\n')
            (*size)++;
    }
    (*size)++;
    arr = malloc(sizeof(char *) * (*size) + 1);
    creation_of_array(arr, map, size, size_str);
    arr[*size] = NULL;
    return arr;
}
