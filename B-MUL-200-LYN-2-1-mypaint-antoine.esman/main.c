/*
** EPITECH PROJECT, 2022
** main
** File description:
** EXECUTE CODE
*/

#include "my.h"
#include "free.h"
#include "create.h"

void render_window(paint_t *p)
{
    while (sfRenderWindow_isOpen(p->window)) {
        event_manager(p);

        update_manager(p);

        display_manager(p);
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_description();
        return 0;
    } if (ac > 2)
        return 84;
    srand( time( NULL ) );

    paint_t *p = malloc(sizeof(paint_t));

    init_manager(p, ac, av);

    render_window(p);

    destroy_manager(p);
    return 0;
}
