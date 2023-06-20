/*
** EPITECH PROJECT, 2023
** src/valid_script
** File description:
** valid_script
*/

#include "../include/my.h"
#include <stddef.h>

int valid_script(char *scriptpath)
{
    FILE *script = fopen(scriptpath, "r");
    if (script == NULL)
        return 0;
    int nb_boat = 0;
    char all_boat[] = "aaaaaaaaaa";
    size_t nb_char = 0;
    char *buffer;

    for (; getline(&buffer, &nb_char, script) != -1; nb_boat++) {
        if (!valid_buffer(buffer, all_boat) || nb_boat == 4) {
            fclose(script); free(buffer);
            return 0;
        }
    }
    fclose(script);
    if (nb_boat != 4 || !(my_strcmp(all_boat, "aa2345aaaa")))
        return 0;
    return 1;
}
