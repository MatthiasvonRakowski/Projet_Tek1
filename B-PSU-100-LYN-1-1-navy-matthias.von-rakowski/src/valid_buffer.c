/*
** EPITECH PROJECT, 2023
** src/valid_buffer
** File description:
** valid_buffer
*/

#include "../include/my.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int valid_pos(char *position)
{
    if (my_strlen(position) != 2)
        return 0;
    if (position[0] < 65 || position[0] > 72)
        return 0;
    if (position[1] < 49 || position[1] > 56)
        return 0;
    return 1;
}

int valid_buffer(char *line, char *all_boat)
{
    if (!valid_boats(line, all_boat))
        return 0;
    char **array = my_str_to_word_array(line);
    if (my_str2dlen(array) != 3) {
        free_array(array);
        return 0;
    }
    int size_boat = my_atoi(array[0]);
    if (size_boat < 2 || size_boat > 5) {
        free_array(array);
        return 0;
    }
    for (int i = 1; array[i] != NULL; i++) {
        if (!valid_pos(array[i])) {
            free_array(array);
            return 0;
        }
    }
    free_array(array);
    return 1;
}
