/*
** EPITECH PROJECT, 2022
** last_file_i_hope
** File description:
** last flag
*/

#include "mylib/include/my.h"

char *path_fonction(char *path, char *name)
{
    char *test;
    char *you;

    if (path[my_strlen_rec(path) - 1] != '/') {
        you = my_strcat(path, "/");
        test = my_strcat(you, name);
        free(you);
    } else
        test = my_strcat(path, name);
    return test;
}

filename_t *find_file(filename_t *file, char *path, int a)
{
    DIR *dirp;
    struct dirent *trip;
    struct stat stats;
    char *new_path;
    dirp = opendir(path);
    while ((trip = readdir(dirp))) {
        new_path = path_fonction(path, trip->d_name);
        stat(new_path, &stats);
        if (trip->d_name[0] == '.' && a == 0)
            continue;
        if ((stats.st_mode & S_IFDIR) != 0 && my_strcmp(trip->d_name, ".") &&
            my_strcmp(trip->d_name, "..")) {
            place_filename(file, new_path);
            file = file->next;
            file = find_file(file, new_path, a);
            free(new_path);
        }
    }
    closedir(dirp);
    return file;
}

void last_flag(file_t *file)
{
    filename_t *temp = file->filename;
    filename_t *nex;

    if (file->nbr_filename == 0) {
        filename_next(file, ".");
        file->filename->next = NULL;
        temp = file->filename;
    }
    while (file->filename){
        nex = file->filename->next;
        find_file(file->filename, file->filename->name, file->a);
        file->filename = nex;
    }
    file->filename = temp;
}

info_t *temp_init(struct dirent *is_dir, info_t *temp)
{
    info_t *malltemp;

    malltemp = malloc(sizeof(info_t));
    malltemp->path = my_strdup(temp->path);
    malltemp->name = my_strdup(is_dir->d_name);
    malltemp->path = path_fonction(malltemp->path, malltemp->name);
    malltemp->next = NULL;
    malltemp->prev = NULL;
    malltemp->subdirectories = NULL;
    return malltemp;
}

void flag_way(info_t *info_write, file_t *file)
{
    if (file->a == 0 && info_write->name[0] == '.')
        return;
    if (file->l == 0) {
        my_putstr_n(info_write->name);
        my_putstr_n(" ");
    } else
        the_l_flag(info_write, file->r, file->d);
}
