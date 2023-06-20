/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** function_launch_command
*/

#ifndef FUNCTION_LAUNCH_COMMAND_H_
    #define FUNCTION_LAUNCH_COMMAND_H_

    #include "../../include/struct_42sh.h"

    // launch_command.c

    void launch_command(s_42sh *sh_42, com_info *com_info, h_info *history);

    // get_paths_and_check_commands.c

    void get_paths(com_info *com_info);
    void command_line(com_info *com_info, ast_node *node, int ele_check);

    //create_path.c

    void create_path(com_info *com);

    // check_error.c

    int check_output(ast_node *node, int child_status, com_info *com_info);
    void check_arch(ast_node *node);

    // free_all.c

    void free_all(h_info *h, com_info *com, s_42sh *sh, int n);

    int buildin(ast_node *root, com_info *com_info, h_info *history,
    s_42sh *sh);

    // launch_command_next.c

    int execute_build(ast_node *root, com_info *com_info,
    h_info *history, s_42sh *sh);

    // buildin_next.c

    void buildin_next(ast_node *root, com_info *com_info, h_info *history,
    s_42sh *sh);

#endif /* !FUNCTION_LAUNCH_COMMAND_H_ */
