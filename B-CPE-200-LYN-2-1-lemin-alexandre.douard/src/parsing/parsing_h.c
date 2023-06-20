/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** parsing_h
*/

#include "lemin.h"
#include "parsing.h"

parsing_t *create_parsing(void)
{
    parsing_t *parse = malloc(sizeof(parsing_t));

    parse->part = ANTS;
    parse->pos = P_NONE;
    parse->is_error = 0;
    parse->strat = NULL;
    parse->end = NULL;
    parse->rooms = NULL;
    parse->nb_rooms = 0;
    parse->links = NULL;
    return parse;
}
