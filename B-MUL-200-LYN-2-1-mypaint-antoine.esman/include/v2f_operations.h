/*
** EPITECH PROJECT, 2022
** v2f_operations.h
** File description:
** V2F_OPERATIONS
*/

#ifndef V2F_OPERATIONS
    #define V2F_OPERATIONS

    #include "my.h"

v2f v2f_multiply_float(v2f v, float x);
v2f v2f_add_float(v2f v, float x);
v2f v2f_add_v2f(v2f v1, v2f v2);
v2f v2i_to_v2f(sfVector2i v);
sfVector2i v2f_to_v2i(v2f v);

#endif /* !V2F_OPERATIONS */
