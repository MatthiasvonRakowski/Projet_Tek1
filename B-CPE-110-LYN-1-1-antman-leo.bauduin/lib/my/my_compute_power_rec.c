/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday05-leo.bauduin
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int result = 1;

    if (p < 0)
        return 0;
    if (p == 0)
        return (1);
    result = nb * my_compute_power_rec(nb, p - 1);
    return result;
}
