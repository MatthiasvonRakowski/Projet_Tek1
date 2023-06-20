/*
** EPITECH PROJECT, 2022
** flag_l
** File description:
** flag a and l and noflag
*/

#include "mylib/include/my.h"

info_t *sort_time(info_t *temp, info_t *list)
{
    info_t *head = list;
    info_t *previous;
    struct stat ctemp;
    struct stat clist;

    temp->subdirectories = NULL;
    stat(temp->name, &ctemp);
    while (list) {
        stat(list->name, &clist);
        if (clist.st_mtime == ctemp.st_mtime && clist.st_mtim.tv_nsec <
                ctemp.st_mtim.tv_nsec)
            break;
        if (clist.st_mtime < ctemp.st_mtime)
            break;
        if (!(list->next))
            previous = list;
        list = list->next;
    }
    return sort_complication(list, temp, previous, head);
}

void init_info(info_t *file)
{
    file = malloc(sizeof(info_t));
    file->next = NULL;
    file->prev = NULL;
    file->subdirectories = NULL;
}

void flag_d(file_t *file)
{
    if (file->nbr_filename != 0) {
        return;
    } else {
        file->filename = malloc(sizeof(filename_t));
        file->filename->name = ".";
    }
}

info_t *my_put_name(file_t *file, info_t *info_writter)
{
    info_t *(*cmp)(info_t *, info_t *);
    if (file->R == 1)
        last_flag(file);
    if (file->d == 1) {
        flag_d(file);
    } else {
        flag_not_a(file);
    }
    if (file->t == 1) {
        cmp = &sort_time;
        info_writter = sort_my_info(info_writter, file, cmp);
    } else {
        cmp = &sort_normal;
        info_writter = sort_my_info(info_writter, file, cmp);
    }
    return info_writter;
}

info_t *flag(file_t *file)
{
    info_t *info_writter;
    init_info(info_writter);

    if (!(file)) {
        file = malloc(sizeof(file_t));
        init(file);
    }
    info_writter = my_put_name(file, info_writter);
    return info_writter;
}
