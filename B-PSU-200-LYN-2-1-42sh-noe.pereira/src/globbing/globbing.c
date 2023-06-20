/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** globbing
*/

#include <glob.h>
#include <string.h>
#include <stdlib.h>

char **globbing(char **arr)
{
    glob_t globbuf;
    int i = 0;
    long unsigned int j = 0;
    char **new_arr = malloc(sizeof(char *) * 100);

    for (i = 0; arr[i] != NULL; i++) {
        glob(arr[i], GLOB_NOCHECK | GLOB_TILDE, NULL, &globbuf);
        for (size_t temp = 0; temp < globbuf.gl_pathc; temp++, j++)
            new_arr[j] = strdup(globbuf.gl_pathv[temp]);
        new_arr[j] = NULL;
    }
    for (int k = 0; arr[k] != NULL; k++)
        free(arr[k]);
    return new_arr;
}
