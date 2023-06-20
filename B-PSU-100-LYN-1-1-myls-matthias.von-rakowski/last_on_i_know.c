/*
** EPITECH PROJECT, 2022
** last_on_i_know.c
** File description:
** file for my_last function
*/

#include "mylib/include/my.h"

void is_sticky(mode_t mode)
{
    my_printf("%c", (mode & S_IROTH) ? 'r' : '-');
    my_printf("%c", (mode & S_IWOTH) ? 'w' : '-');
    if (mode & S_ISVTX)
        my_printf("t");
    else
        my_printf("%c", (mode & S_IXOTH) ? 'x' : '-');
}

void what_files(struct stat info)
{
    switch (info.st_mode & S_IFMT) {
        case S_IFBLK: my_printf("b"); break;
        case S_IFCHR: my_printf("c"); break;
        case S_IFDIR: my_printf("d"); break;
        case S_IFIFO: my_printf("p"); break;
        case S_IFLNK: my_printf("l"); break;
        case S_IFREG: my_printf("-"); break;
        case S_IFSOCK: my_printf("s"); break;
        default: my_printf("u"); break;
        }
}

void place_filename(filename_t *file, char *new_path)
{
    filename_t *newfile = malloc(sizeof(filename_t));

    newfile->name = my_strdup(new_path);
    newfile->next = NULL;
    file->next = newfile;
}
