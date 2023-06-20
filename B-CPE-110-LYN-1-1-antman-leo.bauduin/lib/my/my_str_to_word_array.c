/*
** EPITECH PROJECT, 2022
** Pool-Day8
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

int how_many_space(char const *str, int i)
{
    int count = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] >= 65 && str[i] <= 90)
        || (str[i] >= 97 && str[i] <= 122)) {
            return count;
        }
        count += 1;
    }
    return count;
}

int len_str(char const *str)
{
    int len = my_strlen(str);
    int space = 1;
    int i;

    for (i = 0; i < len; i++) {
        if (!((str[i] >= 65 && str[i] <= 90)
        || (str[i] >= 97 && str[i] <= 122))) {
            i += how_many_space(str, i);
            space += 1;
        }
    }
    if (i == len - 1)
        return 0;
    return space;
}

int len_word(char const *str, int i)
{
    int len = my_strlen(str);
    int alpha = 0;

    for (; i < len; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i]
        >= 97 && str[i] <= 122))
            alpha += 1;
        else
            return alpha;
    }
    return alpha;
}

char *return_word(char const *str, int i, int len_w)
{
    char *word;
    word = malloc(sizeof(char) * len_w + 1);
    int y = 0;

    for (; i < len_w; i++, y++)
        word[y] = str[i];
    word[len_w] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str)
{
    int len_s = len_str(str);
    char **result;
    int len_w;
    int cursor = 0;
    result = malloc(sizeof(char *) * (len_s + 1));

    for (int i = 0; i < len_s; i++) {
        cursor += how_many_space(str, cursor);
        len_w = len_word(str, cursor);
        result[i] = (len_w != 0) ?
            return_word(str, cursor, cursor + len_w) : result[i];
        cursor += len_w + how_many_space(str, cursor);
    }
    result[len_s] = NULL;
    return result;
}
