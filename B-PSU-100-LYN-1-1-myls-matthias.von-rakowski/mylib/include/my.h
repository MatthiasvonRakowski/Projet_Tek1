/*
** EPITECH PROJECT, 2022
** my
** File description:
** all files for mylib
*/

#pragma once
#include "printf.h"
#include "my_ls.h"

file_t *my_params_to_list (int ac, char **av);
int my_delete_nodes(filename_t **begin, void const *data_ref);
int my_strcmp (char const *s1, char const *s2);
void flag_not_a(file_t *file);
void init_file_nbr(DIR *dirp, file_t *file);
info_t *sort_complication(info_t *list, info_t *temp, info_t *last,
    info_t *head);
void init(file_t *file);
char *my_strlowcase(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen_rec(char *str);
info_t *sort_normal(info_t *temp, info_t *list);
info_t *sort_my_info(info_t *info_writter, file_t *file,
    info_t *(*cmp)(info_t *, info_t *));
info_t *sort_time(info_t *temp, info_t *list);
void the_l_flag(info_t *file, int r, int d);
void flag_way(info_t *info_write, file_t *file);
char *my_strdup(char const *str);
void print_next(info_t *info_write, file_t *file);
void print_prev(info_t *info_write, file_t *file);
info_t *temp_init(struct dirent *is_dir, info_t *temp);
void init_info(info_t *file);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char *src);
void init_temp(info_t *temp, DIR *dirp, info_t *(*cmp)(info_t *, info_t *),
file_t *file);
void my_putstr_n(char *str);
void place_filename(filename_t *file, char *new_path);
void last_flag(file_t *file);
void is_sticky(mode_t mode);
void what_files(struct stat info);
void filename_next(file_t *element, char *str);
