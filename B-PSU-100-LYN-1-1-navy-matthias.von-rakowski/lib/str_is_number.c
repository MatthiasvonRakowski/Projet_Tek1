/*
** EPITECH PROJECT, 2022
** str_is_number
** File description:
** a short file description
*/

int str_is_number(char *string)
{
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] < 48 || string[i] > 57)
            return 0;
        i++;
    }
    return 1;
}
