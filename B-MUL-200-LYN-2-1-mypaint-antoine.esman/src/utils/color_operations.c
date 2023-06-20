/*
** EPITECH PROJECT, 2023
** src/utils/color_operations
** File description:
** More develloped operations on colors
*/

#include "my.h"

sfColor black_and_white(sfColor color)
{
    color.r /= 3;
    color.g /= 3;
    color.b /= 3;
    return color;
}

sfColor colored_black_and_white(sfColor color)
{
    color.r *= 3;
    color.g *= 3;
    color.b *= 3;
    return color;
}
