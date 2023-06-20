/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** a short file description
*/

int my_putchar(char);

int my_put_nbr(int nb)
{
    if (nb < 0)
        nb = -nb;
    if (nb < 10) {
        my_putchar(nb + 48);
        return 1;
    }
    int size = my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return 1 + size;
}
