/*
** EPITECH PROJECT, 2023
** src/generator_manager
** File description:
** get_maze
*/

#include "../include/my.h"

void check_buffer(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n') {
            free(buffer);
            exit(84);
        }
    }
}

char **file_length_error(char **file, int error)
{
    if (error == 1) {
        free_maze(file);
        return NULL;
    }
    return file;
}

char **read_file(FILE *fd, int line)
{
    char *buffer = NULL;
    size_t size;
    int i = 0;
    char **file;
    int len_line = 0;
    int error = 0;

    file = malloc(sizeof(char *) * (line + 2));
    while ((getline(&buffer, &size, fd) != -1)) {
        if (len_line != 0 && len_line != strlen(buffer) && (i != line))
            error = 1;
        len_line = strlen(buffer);
        file[i] = strdup(buffer);
        i++;
    }
    file[i] = NULL;
    free(buffer);
    return file_length_error(file, error);
}

char *get_buffer_maze(char *pathfile)
{
    int fd;
    int stat_state;
    char *buffer = NULL;
    struct stat stat_buffer;

    fd = open(pathfile, O_RDONLY);
    stat_state = stat(pathfile, &stat_buffer);
    if (fd == -1 || stat_state == -1) {
        close(fd);
        exit(84);
    }
    if (stat_buffer.st_size == 0) {
        close(fd);
        exit(84);
    }
    buffer = malloc(sizeof(char) * (stat_buffer.st_size + 1));
    read(fd, buffer, stat_buffer.st_size);
    buffer[stat_buffer.st_size] = '\0';
    close(fd);
    return buffer;
}

char **get_maze(char *pathfile)
{
    FILE *fd;
    char *buffer;
    char **maze;

    buffer = get_buffer_maze(pathfile);
    check_buffer(buffer);
    fd = fopen(pathfile, "r");
    maze = read_file(fd, count_line(buffer));
    fclose(fd);
    free(buffer);
    if (maze == NULL)
        exit(84);
    return maze;
}
