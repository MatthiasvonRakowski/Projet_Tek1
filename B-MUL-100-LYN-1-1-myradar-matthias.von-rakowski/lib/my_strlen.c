/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count the number of character of a string
*/

int my_strlen(char *str)
{
    return (str[0] == '\0') ? 0 : (1 + my_strlen(&str[1]));
}
