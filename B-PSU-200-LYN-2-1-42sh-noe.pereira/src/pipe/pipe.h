/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** pipe
*/

#ifndef PIPE_H_
    #define PIPE_H_

    #include "../../include/struct_pipe.h"

    int count_pipe(ast_node *root, int i, pipe_t *s_pipe);

    void parcour_tree_pipe(ast_node *root, com_info *com_info, pipe_t *pipe_s);

    void pipe_exe(com_info *com_info, pipe_t *pipe_s, h_info *history);

    int lauch_pipe(ast_node *root, com_info *com_info, h_info *history,
    s_42sh *sh);

    int execute_pipe_redir(pipe_t *pipe_s, com_info *com_info, h_info *history,
    ast_node *root);

    void set_tab(pipe_t *pipe_s, ast_node *root, com_info *com_info);

    int pipe_exe_next(pipe_t *pipe_s, com_info *com_info,
    h_info *history);

    int execute_process(pipe_t *pipe_s, com_info *com_info,
    h_info *history , ast_node *root);

    void free_pipe(pipe_t *pipe_s);

#endif /* !PIPE_H_ */
