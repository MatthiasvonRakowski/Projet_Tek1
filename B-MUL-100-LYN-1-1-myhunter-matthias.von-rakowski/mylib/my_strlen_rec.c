/*
** EPITECH PROJECT, 2022
** my_strlen_i
** File description:
** count each char of a str
*/

int my_strlen_rec(char *str)
{
    return (str[0] == '\0') ? (0) : 1 + my_strlen_rec(&str[1]);
}
