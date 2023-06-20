/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** myls
*/

#include "mylib/include/my.h"

int check_file(char *av)
{
    DIR *try;
    struct stat stats;

    try = opendir(av);
    if (try == NULL) {
        closedir(try);
        if ((stat(av, &stats) != 0));
            return 0;
        return 1;
    }
    closedir(try);
    return 1;
}

int check_that_flag(char *av)
{
    for (int i = 1; av[i] != '\0'; i++) {
        switch (av[i]) {
            case 'a':
            case 'l':
            case 'd':
            case 'R':
            case 'r':
            case 't': return 1;
            default: return 0;
        }
    }
    return 0;
}

int check_if_good(char *av)
{
    if (av[0] == '-')
        return check_that_flag(av);
    else
        return check_file(av);
}

void ls_writer(file_t *file)
{
    info_t *info_write = flag(file);
    if (file->r == 0)
        print_next(info_write, file);
    else {
        info_write = info_write->last_one;
        print_prev(info_write, file);
    }
}

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (!(check_if_good(av[i])))
            return 84;
    }
    ls_writer(my_params_to_list(ac, av));
    return 0;
}
