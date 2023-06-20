/*
** EPITECH PROJECT, 2023
** src/valid_buffer
** File description:
** valid_connection
*/

#include "../include/my.h"

int valid_connection(char *pid)
{
    int i_pid = my_atoi(pid);
    struct timespec delay = {3, 0};

    signal(SIGUSR2, recieved_handler);
    kill(i_pid, SIGUSR1);
    nanosleep(&delay, NULL);
    if (!signal_receiving(-1))
        return 0;
    return 1;
}
