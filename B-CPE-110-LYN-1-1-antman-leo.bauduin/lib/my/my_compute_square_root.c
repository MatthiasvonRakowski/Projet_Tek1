/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday05-leo.bauduin
** File description:
** my_compute_square_root
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int count = 0;

    while (count * count < nb && count < 46350) {
        count++;
    }
    if (count * count != nb) {
        return 0;
    }
    return count;
}
