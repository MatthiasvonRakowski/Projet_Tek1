/*
** EPITECH PROJECT, 2023
** src/valid_boats
** File description:
** valid_boats
*/

#include "../include/my.h"

int wrong_position(char *line)
{
    if (line[1] != ':' && line[4] != ':')
        return 1;
    if (!(line[0] >= '0' && line[0] <= '9') || !(line[3] >= '0' &&
        line[3] <= '9') || !(line[6] >= '0' && line[6] <= '9'))
        return 1;
    if (!(line[2] >= 'A' && line[2] <= 'Z') || !(line[5] >= 'A' &&
        line[5] <= 'Z'))
        return 1;
    if (line[2] == line[5] && line[6] == (line[3] + line[0] - '1')) {
        return 0;
    } else if (line[3] == line[6] && line[5] == (line[2] + line[0] - '1')) {
        return 0;
    } else {
        return 1;
    }
}

int valid_boats(char *line, char *all_boat)
{
    if (my_strlen(line) != 8)
        return 0;
    int i = 0;
    while (line[i] != '\0') {
        if (!char_is_valid(line[i]))
            return 0;
        i++;
    }
    if (wrong_position(line))
        return 0;
    all_boat[line[0] - '0'] = line[0];
    return 1;
}
