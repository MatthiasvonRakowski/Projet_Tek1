/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** append_char_to_str
*/

#include "../include/struct_42sh.h"

char *append(char *str, char to_add)
{
    char *new_str = NULL;
    int i = 0;

    if (str == NULL) {
        new_str = malloc(sizeof(char) * 2);
        new_str[0] = to_add;
        new_str[1] = '\0';
        return (new_str);
    } else {
        new_str = malloc(sizeof(char) * strlen(str) + 2);
        for (i = 0; str[i] != '\0'; i++) {
            new_str[i] = str[i];
        }
        new_str[i] = to_add;
        new_str[i + 1] = '\0';
    return (new_str);
    }
    return (NULL);
}
