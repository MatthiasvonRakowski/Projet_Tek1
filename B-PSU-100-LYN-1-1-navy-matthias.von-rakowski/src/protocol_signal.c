/*
** EPITECH PROJECT, 2023
** protocol_signal
** File description:
** you're a bad developer
*/

#include "../include/my.h"

char protocol_signal(int signal)
{
    static char code;
    static int signal_pos;
    char tmp;
    char bit = signal == SIGUSR2 ? 1 : 0;

    if (signal == 0)
        return (signal_pos == 6 ? code : (-1));
    if (signal == 1) {
        signal_pos = 0;
        tmp = code;
        code = 0;
        return tmp;
    }
    if (!signal_pos)
        signal_pos = 1;
    else
        signal_pos++;
    code = code | (bit) << (6 - signal_pos);
    return (-1);
}
