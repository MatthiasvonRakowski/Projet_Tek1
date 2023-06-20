/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** alias_replace
*/

#include "../../include/sh42_include.h"

char *add_char(char *str, char c)
{
    char *temp = NULL;

    if (str == NULL) {
        str = malloc(sizeof(char) * 2);
        str[0] = c;
        str[1] = '\0';
        return str;
    }
    temp = strdup(str);
    free(str);
    str = malloc(sizeof(char) * (strlen(temp) + 2));
    strcpy(str, temp);
    str[strlen(temp)] = c;
    str[strlen(temp) + 1] = '\0';
    free(temp);
    return str;
}

char *add_word(char *new_str, char *word)
{
    char *temp = NULL;

    if (new_str == NULL) {
        new_str = strdup(word);
        return new_str;
    }
    temp = strdup(new_str);
    free(new_str);
    new_str = malloc(sizeof(char) * (strlen(temp) +
        strlen(word) + 2));
    strcpy(new_str, temp);
    strcat(new_str, " ");
    strcat(new_str, word);
    strcat(new_str, "\0");
    free(temp);
    return new_str;
}

int search_alias(alias_t *alias, char *word, char **new_str, char *old_alias)
{
    alias_t *temp = alias;

    for (; temp; temp = temp->next) {
        if (strcmp(word, old_alias) == 0)
            return 0;
        if (!strcmp(temp->alias, word)) {
            return (old_alias[0] == '\0') ? search_alias(alias, temp->command,
                new_str, temp->alias) : search_alias(alias,
                temp->command, new_str, old_alias);
        }
    }
    *new_str = add_word(*new_str, word);
    return 1;
}

int detect_alias(char **str, com_info *com_info)
{
    alias_t *temp = com_info->alias_list;
    char *new_str = NULL;
    char word[500] = {0};
    char *clean = clean_str(*str);
    int valid = 1; int j;

    for (int i = 0; clean[i]; i++, temp = com_info->alias_list) {
        for (j = 0; clean[i] != ' ' && clean[i] != '\0' &&
        clean[i] != '\n' && clean[i] != '\t'; i++, j++) word[j] = clean[i];
        word[j] = '\0';
        valid = search_alias(temp, word, &new_str, "");
        if (valid == 0) break;
    }
    free(*str);
    if (valid == 0) {
        if (new_str != NULL) free(new_str);
        write (2, "Alias loop.\n", 12); return -1;
    }
    *str = add_char(new_str, '\n');
    return 0;
}
