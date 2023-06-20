/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Compare 2 string send 1 if it is the same 0 else
*/

int my_strcmpn(char const *str, char const *cmp, int nbr)
{
    int i;

    for (i = 0; str[i] != '\0' && cmp[i] && i < nbr - 1; i++)
        if (str[i] != cmp[i])
            return 0;
    if (str[i] != cmp[i])
        return 0;
    return 1;
}
