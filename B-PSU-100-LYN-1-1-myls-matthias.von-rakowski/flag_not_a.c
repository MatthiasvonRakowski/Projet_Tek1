/*
** EPITECH PROJECT, 2022
** flag_not_a
** File description:
** Not flag a
*/

#include "mylib/include/my.h"

void print_next(info_t *info_write, file_t *file)
{
    if (file->nbr_filename == 1 && file->R == 0 &&
        info_write->subdirectories != NULL) {
        print_next(info_write->subdirectories, file);
        return;
    }
    while (info_write) {
        if (info_write->subdirectories != NULL) {
            my_printf("%s:\n", info_write->name);
            print_next(info_write->subdirectories, file);
            my_printf("\n");
            info_write = info_write->next;
            continue;
        }
        flag_way(info_write, file);
        info_write = info_write->next;
    }
}

void print_prev(info_t *info_write, file_t *file)
{
    if (file->nbr_filename == 1 && file->R == 0 && info_write->subdirectories) {
        print_prev(info_write->subdirectories, file);
        return;
    }
    while (info_write) {
        if (info_write->subdirectories != NULL) {
            my_printf("%s:\n", info_write->name);
            print_prev(info_write->subdirectories, file);
            my_printf("\n");
            info_write = info_write->prev;
            continue;
        }
        flag_way(info_write, file);
        info_write = info_write->prev;
    }
}

void flag_info(file_t *file)
{
    DIR *dirp;
    struct dirent *read_dir;

    while (file->filename) {
        if (!(dirp = opendir(file->filename->name)))
            continue;
        file->filename = file->filename->next;
    }
    closedir(dirp);
}

info_t *sort_normal(info_t *temp, info_t *list)
{
    temp->subdirectories = NULL;
    temp->next = NULL;
    list->next = temp;
    temp->prev = list;
    return temp;
}

void flag_not_a(file_t *file)
{
    DIR *dirp;
    filename_t *temp = NULL;
    struct dirent *read_dir;

    if (file->nbr_filename != 0) {
        return;
    }
    dirp = opendir("./");
    while ((read_dir = readdir(dirp))) {
        if (file->a == 0 && read_dir->d_name[0] == '.')
            continue;
        temp = malloc(sizeof(filename_t));
        temp->name = my_strdup(read_dir->d_name);
        temp->next = file->filename;
        file->filename = temp;
    }
    closedir(dirp);
}
