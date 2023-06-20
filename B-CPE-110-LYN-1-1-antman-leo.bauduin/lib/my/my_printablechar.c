/*
** EPITECH PROJECT, 2022
** printChar
** File description:
** my_printablechar
*/

int my_printablechar(char c)
{
    if (c >= 32 && c <= 127)
        return 1;
    return 0;
}
