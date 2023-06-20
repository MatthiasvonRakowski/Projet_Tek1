/*
** EPITECH PROJECT, 2023
** src/init_map
** File description:
** init maps
*/

#include "../include/my.h"

char **put_boat_in_map(char *buffer, char **map)
{
    if (buffer[2] != buffer[5]) {
        for (int i = buffer[2] - 'A'; i <= buffer[5] - 'A'; i++)
            map[i][buffer[3] - '0' - 1] = buffer[0];
    } else {
        for (int i = buffer[3] - '0' - 1; i <= buffer[6] - '0' - 1; i++) {
            map[buffer[2] - 'A'][i] = buffer[0];
        }
    }
    return map;
}

char **init_map(void)
{
    char **map = malloc(sizeof(char *) * (MAP_HEIGHT + 1));

    for (int i = 0; i < MAP_HEIGHT; i++) {
        map[i] = malloc(sizeof(char) * (MAP_WIDTH + 1));
        for (int j = 0; j < MAP_WIDTH; j++)
            map[i][j] = '.';
        map[i][MAP_WIDTH] = '\0';
    }
    return map;
}

char **init_map_player(char *filepath)
{
    FILE *stream = fopen(filepath, "r");
    size_t nb_char = 0;
    char *buffer;
    char **map = init_map();
    while (getline(&buffer, &nb_char, stream) != -1) {
        map = put_boat_in_map(buffer, map);
    }
    fclose(stream);
    return map;
}
