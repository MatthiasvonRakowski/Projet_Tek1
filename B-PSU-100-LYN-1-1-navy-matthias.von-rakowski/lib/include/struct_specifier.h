/*
** EPITECH PROJECT, 2022
** struct
** File description:
** a short file description
*/

#ifndef STRUCT_
    #define STRUCT_

    #include <stdarg.h>
    #include <stdlib.h>
    #include "my.h"
    #include "struct_flags.h"

struct specifier {
    char specifier;
    void (*display)(va_list, flags_list, int *);
};

const struct specifier SPECIFIERS[] = { {'c', &disp_c}, {'s', &disp_s},
                                        {'d', &disp_d}, {'i', &disp_d},
                                        {'e', &disp_e}, {'E', &disp_ee},
                                        {'f', &disp_f}, {'%', &disp_prc},
                                        {'n', &disp_n}, {'o', &disp_o},
                                        {'x', &disp_x}, {'X', &disp_xx},
                                        {'u', &disp_u}, {'S', &disp_ss},
                                        {'b', &disp_b}, {'p', &disp_p} ,
                                        {'g', &disp_g}};

#endif /* STRUCT_ */
