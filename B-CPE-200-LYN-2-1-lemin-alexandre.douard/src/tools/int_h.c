/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** int_h
*/

#include "lemin.h"
#include <math.h>

char *int_to_string(int num)
{
    static char buffer[MAX_DIGITS + 1];
    int i = 0;
    int is_negative = (num < 0) ? 1 : 0;
    int len = 0;
    char c;
    num = (num < 0) ? -num : num;
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num != 0);
    if (is_negative)
        buffer[i++] = '-';
    buffer[i] = '\0';
    len = my_strlen(buffer);
    for (int j = 0; j < len / 2; j++) {
        c = buffer[j];
        buffer[j] = buffer[len - j - 1];
        buffer[len - j - 1] = c;
    }
    return buffer;
}

int int_arr_max(int *arr, int len)
{
    int max = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int int_arr_max_ind(int *arr, int ind_start, int ind_end)
{
    int max = 0;

    for (int i = ind_start; i < ind_end; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

char is_num(char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    if (str[i] == '-')
        i++;
    if (str[i] == 0)
        return 0;
    for (i; str[i]; i++) {
        if (!IS_DIG(str[i]))
            return 0;
    }
    return 1;
}

int int_arr_min(int *arr, int len)
{
    int max = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
