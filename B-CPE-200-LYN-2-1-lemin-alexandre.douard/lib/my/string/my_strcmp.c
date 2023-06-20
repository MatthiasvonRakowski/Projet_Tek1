/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** compare two string and tells which one is the biggest
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    if (s1[i])
        return s1[i];
    if (s2[i])
        return -s2[i];
    return 0;
}
