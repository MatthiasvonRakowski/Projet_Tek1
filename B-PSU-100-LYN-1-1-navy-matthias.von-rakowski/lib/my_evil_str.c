/*
** EPITECH PROJECT, 2022
** my_evil_str
** File description:
** a short file description
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    char *result = str;
    char save;
    if (len == 1) {
            return str;
        }
    while (i < (len / 2)) {
        save = result[len - 1 - i];
        str[len - 1 - i] = result[i];
        str[i] = save;
        i ++;
    }
    return str;
}
