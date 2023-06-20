/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count the number of characters in a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
