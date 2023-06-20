/*
** EPITECH PROJECT, 2023
** src/wait_pid
** File description:
** wait pid
*/

#include "../include/my.h"

void signal_pid(int signal, siginfo_t *info, void *context)
{
    send_pid(info);
}
