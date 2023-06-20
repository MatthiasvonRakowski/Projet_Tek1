/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** varenv_replace
*/

#include "../../include/struct_42sh.h"
#include "varenv.h"

static char *get_var_cont(char *env)
{
    char *str = malloc(sizeof(char) * strlen(env) + 1);
    int i = 0; int j = 0;

    for (; env[i] != '='; i++);
    i = i + 1;
    for (; env[i] != '\0'; i++) {
        str[j] = env[i];
        j++;
    }
    return (str);
}

static char *remove_shortcut_bis(char *str, char *word, int word_size, int i)
{
    for (; str[i + word_size + 1] != '\0'; i++) {
        str[i] = str[i + word_size + 1];
    }
    str[i] = '\0';
    return (str);
}

static char *remove_shortcut(char *str, char *word, int *emplacement)
{
    int word_size = strlen(word);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '$') {
            (*emplacement) = i;
            str = remove_shortcut_bis(str, word, word_size, i);
        }
    }
    return (str);
}

static char *add_var_content(char *str, char *var_content, int emplacement)
{
    int i = 0; int j = 0;
    char *final_str = malloc(sizeof(char) *
    (strlen(str) + strlen(var_content) + 1));
    char *temp_str = malloc(sizeof(char) * strlen(str) + 1);

    for (i = 0; i < emplacement; i++) {
        final_str[i] = str[i];
    }
    final_str[i] = '\0';
    for (; str[i] != '\0'; i++) {
        temp_str[j] = str[i];
        j++;
    }
    temp_str[j] = '\0';
    strcat(final_str, var_content);
    strcat(final_str, temp_str);
    return (final_str);
}

char *replace_var(char *env, char *str, char *word)
{
    int emplacement = 0;
    char *var_content = get_var_cont(env);

    str = remove_shortcut(str, word, &emplacement);
    str = add_var_content(str, var_content, emplacement);
    return (str);
}
