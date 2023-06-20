/*
** EPITECH PROJECT, 2022
** the_l_flag
** File description:
** the_l_flag
*/

#include "mylib/include/my.h"

void is_dir_and_permission(struct stat file_info)
{
    mode_t temp;

    what_files(file_info);
    for (int i = 0; i < 6; i += 3) {
        temp = file_info.st_mode;
        temp <<= 23 + i;
        temp >>= 29;
        switch (temp) {
            case 0: my_printf("---"); continue;
            case 1: my_printf("--x"); continue;
            case 2: my_printf("-w-"); continue;
            case 3: my_printf("-wx"); continue;
            case 4: my_printf("r--"); continue;
            case 5: my_printf("r-x"); continue;
            case 6: my_printf("rw-"); continue;
            case 7: my_printf("rwx"); continue;
        }
    }
    is_sticky(file_info.st_mode);
}

void my_get_guid(uid_t uid, gid_t gid)
{
    struct passwd *getuid = getpwuid(uid);
    struct group *getgid = getgrgid(gid);

    my_printf("%s %s ", getuid->pw_name, getgid->gr_name);
}

void my_get_time(struct timespec time)
{
    char *date = ctime(&time);
    char date_l[30];
    int i = 0;
    int k = 0;

    for (; date[i] != ' '; i++);
    for (int h = 0; h < 2; k++, i++) {
        if (date[i] == ':')
            h++;
        date_l[k] = date[i];
    }
    date_l[k - 1] = '\0';
    my_printf("%s ", date_l);
}

void total(info_t *file, int r)
{
    info_t *temp = file;
    struct stat stats;
    long int count = 0;

    if (r == 0)
        while (file->next) {
            stat(file->path, &stats);
            count += stats.st_blocks;
            file = file->next;
        } else
        while (file->prev) {
            stat(file->path, &stats);
            count += stats.st_blocks;
            file = file->prev;
        }
    stat(file->path, &stats);
    my_printf("total %li\n", (count + stats.st_blocks) / 2);
    file = temp;
}

void the_l_flag(info_t *file, int r, int d)
{
    struct stat file_info;

    if (((file->prev == NULL && r == 0) || (file->next == NULL && r == 1)) &&
        d == 0)
        total(file, r);
    stat(file->path, &file_info);
    is_dir_and_permission(file_info);
    my_printf(" %u ", file_info.st_nlink);
    my_get_guid(file_info.st_uid, file_info.st_gid);
    if (file_info.st_rdev == 0) {
        my_printf("%u ", file_info.st_size);
    } else {
        my_printf("%d, %d", major(file_info.st_rdev), minor(file_info.st_rdev));
    }
    my_get_time(file_info.st_mtim);
    my_putstr_n(file->name);
    my_putstr_n("\n");
}
