/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** from a str to a word array
*/

#include <unistd.h>
#include <stdlib.h>

int verify_me (char c)
{
    if (c != ' ' && c != '\n' && c != '\t')
        return 1;
    return 0;
}

int number_of_lines (char const *str)
{
    int count = 1;
    int i = 0;

    for (; str[i] != '\0'; i++){
        if (!verify_me(str[i]) && verify_me(str[i - 1])) {
            count++;
        }
    }
    if (count > 1 && verify_me(str[i - 1])) {
        count++;
    }
    return (count);
}

int cnt_wd(char const *str, int place_str)
{
    int count = 0;

    for (;str[place_str] != '\0' && verify_me(str[place_str]); place_str++){
            count++;
    }
    return (count + 1);
}

char **my_str_to_word_array (char const *str)
{
    int count = number_of_lines(str);
    char **tab = malloc (sizeof(char*) * count);
    int place_str = 0;
    int place_chr = 0;

    for (int line = 0; str[place_str] != '\0'; line++) {
        if (!verify_me(str[place_str])) {
            place_str++;
            line--;
            continue;
        }
        tab[line] = malloc (sizeof(char) * cnt_wd(str, place_str));
        for (place_chr = 0; verify_me(str[place_str]); place_chr++) {
            tab[line][place_chr] = str[place_str];
            place_str++;
        }
        tab[line][place_chr] = '\0';
    }
    tab[count - 1] = NULL;
    return tab;
}
