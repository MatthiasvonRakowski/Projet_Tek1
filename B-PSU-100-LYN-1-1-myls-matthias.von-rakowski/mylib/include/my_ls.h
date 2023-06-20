/*
** EPITECH PROJECT, 2022
** mylib/include/bsq_i
** File description:
** my_ls lib
*/

#pragma once
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <sys/sysmacros.h>

typedef struct filename_s {
    char *name;
    struct filename_s *next;
} filename_t;

typedef struct file_s {
    int a;
    int l;
    int R;
    int r;
    int d;
    int t;
    int existe;
    int nbr_filename;
    filename_t *filename;
    filename_t *readdir;
    struct file_s *next;
} file_t;

typedef struct info_s {
    char *name;
    char *path;
    int nbr_element;
    struct info_s *next;
    struct info_s *prev;
    struct info_s *last_one;
    struct info_s *subdirectories;
} info_t;

info_t *flag(file_t *file);
