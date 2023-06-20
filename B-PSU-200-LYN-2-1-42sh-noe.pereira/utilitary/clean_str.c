/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** clean_str
*/

#include "../include/struct_42sh.h"

/*
    NOTE:
        Function that convert TAB to space
*/
static char *convert_tab_to_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 9)
            str[i] = ' ';
    }
    return (str);
}

/*
    NOTE:
        Function that remove space
*/
static char *remove_space(char *str)
{
    int a = 0; int b = 0;
    char *temp = malloc(sizeof(char) * strlen(str) + 1);
    if (str[0] == ' ') {
        for (; str[a] == ' '; a++);
    }
    for (; str[a] != '\0'; a++) {
        temp[b] = str[a]; b++;
    } temp[b] = '\0';
    return (temp);
}

/*
    NOTE:
        Function that remove end line break
*/
static char *remove_line_break(char *str)
{
    int i = strlen(str);
    if (str[i - 1] == '\n')
        str[i - 1] = '\0';
    return (str);
}

/*
    NOTE:
        Function that remove the end space
*/
static char *remove_end_space(char *str)
{
    int i = strlen(str); i--;
    for (; i > 0; i--) {
        if (str[i] != ' ') return (str);
        str[i] = '\0';
    }
    return (str);
}

/*
    NOTE:
        A simply cleaner str (remove space, tab, and \n at end and
        begining of a str, convert tab to space)
*/
char *clean_str(char *str)
{
    str = convert_tab_to_space(str);
    str = remove_space(str);
    str = remove_line_break(str);
    str = remove_end_space(str);
    return (str);
}
