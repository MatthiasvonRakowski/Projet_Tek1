/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** struct_pipe
*/

#ifndef STRUCT_PIPE_H_
    #define STRUCT_PIPE_H_

    #include "struct_42sh.h"

    typedef struct pipe_s {

        int a;
        int b;
        int c;
        int num;

        bool redir;
        bool trunc;
        bool stop;

        int nb_pipe;
        int c_pipe;
        int save_j;
        int next_cmd_exist;
        int *fd;

        char *filepath;

        char ***tab_of_pipe_cmd;

        ast_node **tab_of_node;
        s_42sh *sh;

    } pipe_t;


#endif /* !STRUCT_PIPE_H_ */
