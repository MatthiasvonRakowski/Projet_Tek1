/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** put each letter in lower cases
*/

char *my_strlowcase (char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= ('A' - 'a');
        }
    }
    return str;
}
