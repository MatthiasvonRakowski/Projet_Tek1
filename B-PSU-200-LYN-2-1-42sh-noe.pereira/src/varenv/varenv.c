/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** varenv
*/

#include "../../include/struct_42sh.h"
#include "varenv.h"

static char *get_word_env(char *str, int i)
{
    int j = 0;
    char *word = malloc(sizeof(char) * strlen(str) + 1);
    i = i + 1;

    for (; str[i] != ' ' && str[i] != '\n' && str[i] != '\0' &&
    str[i] != '\t' && str[i] != '"' && str[i] != '\''; i++) {
        word[j] = str[i]; word[j + 1] = '\0'; j++;
    }
    return (word);
}

static int search_word_in_env(char **envi, char *word)
{
    int i = 0; int j = 0;
    char *temp = NULL;

    for (i = 0; envi[i] != NULL; i++) {
        for (j = 0; envi[i][j] != '='; j++) {
            temp = append(temp, envi[i][j]);

        }
        if (strcasecmp(temp, word) == 0) {
            return (i);
        }
        temp = NULL;
    }
    return (-1);
}

static char *varenv(com_info *com_info, char *str, char *word, int *error)
{
    int i = search_word_in_env(com_info->envi, word);

    if (i < 0) {
        printf("%s: Undefined variable.\n", word);
        (*error) = -1;
        return (str);
    } else {
        str = replace_var(com_info->envi[i], str, word);
        return (str);
    }
    return (str);
}

char *clean_before_first_char(char *str)
{
    char *new_str = NULL;
    int i = 0;

    for (; str[i] && str[i] == ' ' && str[i] == '\t'; i++);
    if (str[i] == '&' && str[i + 1] == '&')
        i += 2;
    new_str = strdup(&str[i]);
    free(str);
    return new_str;
}

int detect_varenv(s_42sh *sh_42, com_info *com_info, h_info *history)
{
    int error = 0;
    char *str = clean_before_first_char(strdup(sh_42->com_line));
    char *word = NULL;

    error = detect_alias(&str, com_info);
    for (int i = 0; error != -1 && str[i] != '\n'; i++) {
        if (str[i] == '$') {
            word = get_word_env(str, i);
            str = varenv(com_info, str, word, &error);
        }
    }
    sh_42->com_line = strdup(str);
    free(str);
    if (error == -1)
        return (-1);
    return (0);
}
