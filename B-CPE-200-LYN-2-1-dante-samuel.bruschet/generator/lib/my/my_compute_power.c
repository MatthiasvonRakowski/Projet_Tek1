/*
** EPITECH PROJECT, 2022
** lib/my_compute_power
** File description:
** make a number to the ith power
*/

int my_compute_power(int nbr, int power)
{
    if (power == 0)
        return 1;
    return nbr * my_compute_power(nbr, power - 1);
}
