/*
** EPITECH PROJECT, 2023
** src/wait_pid
** File description:
** wait pid
*/

#include "../include/my.h"

void wait_pid(player_t **player)
{
    struct sigaction sa;

    sa.sa_sigaction = signal_pid;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    while (send_pid(NULL) == -1)
        usleep(100);
    (*player)->pid = send_pid(NULL);
    kill((*player)->pid, SIGUSR2);
}
