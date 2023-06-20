/*
** EPITECH PROJECT, 2022
** Pool-Day4
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int reverse = *a;
    *a = *b;
    *b = reverse;
}
