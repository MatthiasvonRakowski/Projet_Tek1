/*
** EPITECH PROJECT, 2022
** init_info_s
** File description:
** Sort all object
*/

#include "mylib/include/my.h"

info_t *sort_complication(info_t *list, info_t *temp, info_t *last,
        info_t *head)
{
    if (list == NULL) {
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        return head;
    }
    if (head == list) {
        list->prev = temp;
        temp->next = list;
        temp->prev = NULL;
        return temp;
    }
    temp->prev = list->prev;
    list->prev->next = temp;
    list->prev = temp;
    temp->next = list;
    return head;
}

info_t *sort_continue_info(info_t *info_writter)
{
    info_t *temp_of_temp = info_writter;
    int count = 0;

    while (info_writter->prev)
        info_writter = info_writter->prev;
    temp_of_temp = info_writter;
    while (info_writter->next) {
        info_writter = info_writter->next;
        count++;
    }
    info_writter->nbr_element = count;
    temp_of_temp->last_one = info_writter;
    info_writter = temp_of_temp;
    info_writter->nbr_element = count;
    return info_writter;
}

void init_temp(info_t *temp, DIR *dirp, info_t *(*cmp)(info_t *, info_t *),
file_t *file)
{
    struct dirent *isdir;
    info_t *temp_of_temp;

    isdir = readdir(dirp);
    temp->subdirectories = temp_init(isdir, temp);
    while ((isdir = readdir(dirp))) {
        if (file->a == 0 && isdir->d_name[0] == '.') {
            continue;
        }
        temp_of_temp = temp_init(isdir, temp);
        temp->subdirectories = (*cmp)(temp_of_temp, temp->subdirectories);
        temp_of_temp = temp_of_temp->next;
    }
    temp->subdirectories = sort_continue_info(temp->subdirectories);
}

info_t *sort_continue_info_mult(info_t *info_writter, file_t *file,
    info_t *(*cmp)(info_t *, info_t *))
{
    DIR *dirp;
    info_t *temp;
    struct stat stats;

    temp = info_writter;
    while (temp) {
        stat(temp->path, &stats);
        if ((stats.st_mode & S_IFDIR) == 0) {
            temp = temp->next;
            continue;
        }
        dirp = opendir(temp->path);
        init_temp(temp, dirp, cmp, file);
        closedir(dirp);
        temp = temp->next;
    }
    return info_writter;
}

info_t *sort_my_info(info_t *info_writter, file_t *file,
    info_t *(*cmp)(info_t *, info_t *))
{
    info_t *temp;

    info_writter = malloc(sizeof(info_t));
    info_writter->name = my_strdup(file->filename->name);
    info_writter->path = my_strdup(info_writter->name);
    info_writter->prev = NULL;
    info_writter->next = NULL;
    info_writter->subdirectories = NULL;
    file->filename = file->filename->next;
    for (; file->filename; file->filename = file->filename->next) {
        temp = malloc(sizeof(info_t));
        temp->name = my_strdup(file->filename->name);
        temp->path = my_strdup(temp->name);
        info_writter = (*cmp)(temp, info_writter);
    }
    if (file->nbr_filename == 0 || file->d == 1)
        return sort_continue_info(info_writter);
    else
        return sort_continue_info_mult(sort_continue_info(info_writter),
            file, cmp);
}
