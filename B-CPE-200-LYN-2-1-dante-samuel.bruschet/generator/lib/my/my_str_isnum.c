/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** return 1 if it only contains digits, 0 otherweise
*/

int my_str_isnum (char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] <= '9' && str[i] >= '0')) {
            return 0;
        }
    }
    return 1;
}
