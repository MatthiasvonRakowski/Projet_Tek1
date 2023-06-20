/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday05-leo.bauduin
** File description:
** my_is_prime
*/

int my_compute_square_root(int nb);
int my_is_prime(int nb)
{
    if (nb < 2)
        return (0);

    for (int i = 2; i < nb && i < 46350; i++)
        if (nb % i == 0)
            return (0);
    return (1);
}
