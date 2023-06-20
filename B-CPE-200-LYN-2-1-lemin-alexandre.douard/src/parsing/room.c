/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-lemin-alexandre.douard
** File description:
** room
*/

#include "parsing.h"
#include "my.h"
#include <stdlib.h>

room_t *create_room(char *name, vector_t cdt)
{
    room_t *ret = malloc(sizeof(room_t));

    ret->used = false;
    ret->visited = false;
    ret->name = name;
    ret->cdt = cdt;
    ret->state = NONE;
    ret->links = NULL;
    ret->links_num = 0;
    return ret;
}

static void proom(room_t *room)
{
    my_putstr(room->name);
    my_putstr(" ");
    my_putnbr(room->cdt.x);
    my_putstr(" ");
    my_putnbr(room->cdt.y);
    my_putstr("\n");
}

void display_rooms(room_t **rooms)
{
    for (int i = 0; rooms[i]; i++)
        if (rooms[i]->state == START) {
            my_putstr("##start\n");
            proom(rooms[i]);
            break;
        }
    for (int i = 0; rooms[i]; i++)
        if (rooms[i]->state == END) {
            my_putstr("##end\n");
            proom(rooms[i]);
            break;
        }
    for (int i = 0; rooms[i]; i++) {
        if (rooms[i]->state == NONE)
            proom(rooms[i]);
    }
}

room_t *get_room(room_t **rooms, char const *name)
{
    int i = 0;

    while (my_strcmp(rooms[i]->name, name))
        i++;
    return rooms[i];
}
