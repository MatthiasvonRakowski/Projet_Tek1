/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** rm_allspace
*/

#include "../include/struct_42sh.h"

char *rm_allspace(char *buffer)
{
    char *str = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(str, buffer);
    int count_non_spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[count_non_spaces] = str[i];
            count_non_spaces++;
        }
    }
    str[count_non_spaces] = '\0';
    return (str);
}
