/*
** EPITECH PROJECT, 2023
** src/send_pid
** File description:
** send pid
*/

#include "../include/my.h"

pid_t send_pid(siginfo_t *info)
{
    static pid_t pid;

    if (info != NULL) {
        pid = info->si_pid;
    }
    if (!pid)
        return (-1);
    return pid;
}
