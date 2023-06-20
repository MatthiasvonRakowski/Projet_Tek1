/*
** EPITECH PROJECT, 2022
** Pool-Day6
** File description:
** my_str_isalpha
*/

int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    int len = my_strlen(str);
    int count = 0;

    for (int i = 0; ((str[i] >= 65) && (str[i] <= 90)) || (((str[i] >= 97)
        && (str[i] <= 122)) && (i < len)); i++)
        count += 1;

    if (count == len) {
        return (1);
    }
    return (0);
}
