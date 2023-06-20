/*
** EPITECH PROJECT, 2023
** 3_MyPaint
** File description:
** get_distance
*/

#include "my.h"
#include <math.h>

int get_distance(sfVector2i prev_pos, sfVector2i pos)
{
    return sqrt(SQUARE((prev_pos.x - pos.x)) + SQUARE((prev_pos.y - pos.y)));
}
