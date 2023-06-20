/*
** EPITECH PROJECT, 2022
** my_params_to_list
** File description:
** creates a new list of argument
*/

#include "include/my.h"

void flag_my_ls(file_t *element, char *av)
{
    for (int i = 1; av[i]; i++) {
        switch (av[i]) {
            case 'a': element->a = 1; break;
            case 'l': element->l = 1; break;
            case 'R': element->R = 1; break;
            case 'r': element->r = 1; break;
            case 'd': element->d = 1; break;
            case 't': element->t = 1; break;
            default: element->existe = 1; break;
        };
    }
}

void init(file_t *element)
{
    element->existe = 0;
    element->a = 0;
    element->l = 0;
    element->R = 0;
    element->r = 0;
    element->d = 0;
    element->t = 0;
    element->filename = NULL;
    element->nbr_filename = 0;
}

void filename_next(file_t *element, char *str)
{
    filename_t *tmp = malloc(sizeof(filename_t));
    tmp->name = str;
    tmp->next = element->filename;
    element->filename = tmp;
    element->nbr_filename += 1;
}

file_t *my_params_to_list (int ac, char **av)
{
    file_t *element = malloc(sizeof(file_t));

    init(element);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            flag_my_ls(element, av[i]);
        else {
            filename_next(element, av[i]);
        }
    }
    return element;
}
