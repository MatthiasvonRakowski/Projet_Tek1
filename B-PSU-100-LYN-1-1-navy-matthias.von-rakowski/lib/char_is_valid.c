/*
** EPITECH PROJECT, 2022
** char_is_alpha_num
** File description:
** a short file description
*/

int char_is_valid(char c)
{
    if ((c >= 48) && (c <= 57))
        return 1;
    if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
        return 1;
    if (c == 10 || c == 58)
        return 1;
    return 0;
}
