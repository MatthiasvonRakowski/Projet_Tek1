/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** a short file description
*/

#include "../include/my.h"

int char_is_alpha_num(char c)
{
    if ((c >= 48) && (c <= 57))
        return 1;
    if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
        return 1;
    return 0;
}

void verif_separation(int *separator, int *count_word)
{
    if (*separator == 1) {
        *count_word += 1;
        *separator = 0;
    }
}

int count_word(char *str)
{
    int separator = 1;
    int count_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (char_is_alpha_num(str[i]))
            verif_separation(&separator, &count_word);
        else
            separator = 1;
    }
    return count_word;
}

int my_word_len(char const *str)
{
    int i = 0;
    while (char_is_alpha_num(str[i]))
        i++;
    return i;
}

char **my_str_to_word_array(char *str)
{
    char temp[] = "aaaaaaaaaa";
    int word_len = 0;
    char **array;
    int i = 0;
    if (!valid_boats(str, temp))
        return NULL;
    int nb_word = count_word(str);
    array = malloc(sizeof(char*) * (nb_word + 1));
    for (i = 0; i < nb_word; i++) {
        while (!char_is_alpha_num(*str))
            str++;
        word_len = my_word_len(str);
        array[i] = malloc(sizeof(char) * (word_len + 1));
        my_strncpy(array[i], str, word_len);
        str += word_len;
    }
    array[nb_word] = NULL;
    return array;
}
