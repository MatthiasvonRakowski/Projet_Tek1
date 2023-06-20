/*
** EPITECH PROJECT, 2022
** v2f_operations
** File description:
** v2f_operations
*/

#include "my.h"

v2f v2f_multiply_float(v2f v, float x)
{
    v2f new_v;

    new_v.x = v.x * x;
    new_v.y = v.y * x;
    return new_v;
}

v2f v2f_add_float(v2f v, float x)
{
    v2f new_v;

    new_v.x = v.x + x;
    new_v.y = v.y + x;
    return new_v;
}

v2f v2f_add_v2f(v2f v1, v2f v2)
{
    v2f new_v;

    new_v.x = v1.x + v2.x;
    new_v.y = v1.y + v2.y;
    return new_v;
}

v2f v2i_to_v2f(sfVector2i v)
{
    v2f new_v;

    new_v.x = v.x;
    new_v.y = v.y;
    return new_v;
}

sfVector2i v2f_to_v2i(v2f v)
{
    sfVector2i new_v;

    new_v.x = v.x;
    new_v.y = v.y;
    return new_v;
}
