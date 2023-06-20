/*
** EPITECH PROJECT, 2023
** src/signal_receiving
** File description:
** if you code on paper, you're not a real programmer
*/

#include "../include/my.h"

int signal_receiving(int signal)
{
    static int signal_answer;
    char bit = signal == SIGUSR2 ? 1 : 0;

    if (signal == -1)
        return signal_answer;
    if (bit == 1) {
        signal_answer = 1;
    } else {
        signal_answer = 0;
    }
    return 0;
}
