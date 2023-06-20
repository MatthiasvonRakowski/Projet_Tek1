/*
** EPITECH PROJECT, 2023
** 3_MyPaint
** File description:
** same_colors
*/

#include "my.h"

int same_colors(sfColor color1, sfColor color2)
{
    if (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b
    && color1.a == color2.a)
        return 1;
    else
        return 0;
}
