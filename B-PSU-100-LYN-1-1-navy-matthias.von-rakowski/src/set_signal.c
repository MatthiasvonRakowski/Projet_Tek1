/*
** EPITECH PROJECT, 2023
** set_signal
** File description:
** you're a bad developer
*/

#include "../include/my.h"

void set_signal(void)
{
    signal(SIGUSR1, &signal_handling);
    signal(SIGUSR2, &signal_handling);
}
