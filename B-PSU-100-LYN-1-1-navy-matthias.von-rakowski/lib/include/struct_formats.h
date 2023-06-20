/*
** EPITECH PROJECT, 2022
** struct
** File description:
** a short file description
*/

#ifndef STRUCT_FORMAT_
    #define STRUCT_FORMAT_

    #include <stdarg.h>
    #include <stdlib.h>
    #include "my.h"

struct list_formats {
    char specifier;
};

const struct list_formats LIST_FLAGS[] = { {'#'}, {'0'}, {' '}, {'+'}, {'-'} };

#endif /* STRUCT_FORMAT_ */
