/*
** EPITECH PROJECT, 2023
** lib/getline_in_array
** File description:
** put a line in an array and return 1 if it is only number and if it feels the
** array, 0 else
*/

#include <stdio.h>
int my_getnbr_i(char const *str, int *i);
int my_str_isnum(const char *str);

int my_getline_in_array(char const *str, int *arr, int size)
{
    int j = 0;
    int i = 0;

    for (; str[j] && i < size; i++, j++) {
        if (str[j] == ' ' && str[j] == '\t') {
            i--;
            continue;
        }
        if (!(str[j] <= '9' && str[j] >= '0'))
            return 0;
        arr[i] = my_getnbr_i(str, &j);
        if (str[j] <= '9' && str[j] >= '0')
            j--;
        if (!(str[j] == ' ' || str[j] == '\t'))
            return 0;
    }
    if (i != size)
        return 0;
    return 1;
}
