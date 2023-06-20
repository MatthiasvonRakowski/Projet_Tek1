/*
** EPITECH PROJECT, 2022
** /home/matthias_vr/Epitech/project/my_radar/bsmy_radar/src/bs_my_radar
** File description:
** man man
*/

#include "../include/my.h"
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <stdio.h>

void delta_t(sfClock *clock, double *delta, double *timer, int time_speed)
{
    sfTime time = sfClock_getElapsedTime(clock);

    *delta = time.microseconds * time_speed / 1000000.0;
    *timer += *delta;
    if (delta > 0)
        sfClock_restart(clock);
}

int gloop(FILE *fd)
{
    data_t *data = init_data(fd);

    if (data == NULL || (!data->norme.window))
        return 84;
    while (sfRenderWindow_isOpen(data->norme.window)) {
        delta_t(data->norme.clock, &data->norme.delta_t, &data->norme.timer,
        data->norme.time_speed);
        data->norme = event_manager(data);
        update_manager(data);
        draw_manager(data);
    }
    destroy_manager(data);
    return 0;
}

void print_msg(void)
{
    my_putstr("Air traffic simulation panel\nUSAGE\n  ./my_radar [OPTIONS] ");
    my_putstr("Path_to_script\n   path_to_script    The path to the script ");
    my_putstr("file.\n\nOPTIONS\n  -h              print the usage and quit.");
    my_putstr("\n\n");
    my_putstr("USER INTERACTIONS\n  'L' key      enable/disable hitboxes and ");
    my_putstr("areas.\n  'S' key      enable/disable sprites.\n  '->' acceler");
    my_putstr("ation until x16\n  '<-' deceleration\n");
}

int main(int ac, char **av)
{
    FILE *fd;
    int rtn;

    if (ac != 2) {
        write(2, "Filepath not found, use \"-h\"\n", 30);
        return 84;
    }
    if ((my_strcmp("-h", av[1]))) {
        print_msg();
        return 0;
    }
    fd = fopen(av[1], "r");
    if (fd == NULL) {
        write(2, "Filepath not found, use \"-h\"\n", 30);
        return 84;
    }
    rtn = gloop(fd);
    fclose(fd);
    return rtn;
}
