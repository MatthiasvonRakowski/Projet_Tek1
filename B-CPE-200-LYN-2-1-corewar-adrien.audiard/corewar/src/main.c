/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stdio.h>
#include "corewar.h"
#include "initialisation.h"
#include "free.h"
#include "tools.h"

static int error_handler(int ac, char **av)
{
    if (ac < 2) {
        my_puterror("Usage: ");
        my_puterror(av[0]);
        my_puterror(" [-dump nbr_cycle] [[-n prog_number] [-a load_address]");
        my_puterror(" prog_name]\n");
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (error_handler(ac, av) == 84)
        return 84;
    corewar_t *corewar = malloc(sizeof(corewar_t));

    corewar->visual = false;
    if (init_corewar(corewar, ac, av) == 84) {
        free_corewar(corewar);
        return 84;
    }

    war_loop(corewar);

    put_winner(corewar);
    free_corewar(corewar);
    return 0;
}
