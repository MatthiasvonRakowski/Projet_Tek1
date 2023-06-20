/*
** EPITECH PROJECT, 2022
** sfRenderWindow
** File description:
** csfml window
*/

#include "include/my.h"
#include "mylib/include/printf.h"

int gloop(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    gdata_t *gdata;

    window = sfRenderWindow_create(mode, "my_hunter", sfDefaultStyle, NULL);
    if (!window)
        return EXIT_FAILURE;
    gdata = init_gdata(gdata);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setView(window, gdata->view);
    gdata->clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        sfClock_restart(gdata->clock);
        event_manager(window, gdata);
        update_manager(gdata);
        draw_manager(window, gdata);
    }
    destroy(gdata);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}

void info_hunt(void)
{
    my_printf("Welcome in my Hunter, write only ./my_hunter to play.\n");
    my_printf("You will have to clean the world, for saving it!\n");
    my_printf("------------------------------------------------------------\n");
    my_printf("You can click on the left button to kill your ennemies,\n");
    my_printf("and if you click on echap you will exit the game.\n");
    my_printf("------------------------------------------------------------\n");
    my_printf("Now you can play in the game,\n");
    my_printf("GOOD LUCK AND HAVE FUN!!!");
}

int main (int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        info_hunt();
        return 0;
    }
    if (ac > 1)
        return 84;
    return gloop();
}
