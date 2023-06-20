/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** history_functions
*/
#include "../../include/struct_42sh.h"

#ifndef HISTORY_FUNCTIONS_H_
    #define HISTORY_FUNCTIONS_H_

    // history_functions.c

    int store_history_com(h_info *history, s_42sh *sh, int size);
    void init_var(s_42sh *sh_42, com_info *com_info, h_info *history);
    void print_history(h_info *history);

    // add_red_in_str.c

    int *add_red(char *str, int check, int *ij);

    // cleaner_str.c

    char *cleaner_str(char *s, int size);

    // add_and_rmv_history_cell.c

    void add_first_cell(h_info *history, char *clean);
    void added_new_command(h_info *h, char *str);
    void pass_in_front_com(h_info *history, char *str, int check);

    // execute_history_com.c

    void history_functions(ast_node *root, h_info *history);

    // change_str_history_command.c

    int change_string_old_command(s_42sh *sh, h_info *history);

    // add_com_nb.c

    int add_com_nb(s_42sh *sh, int i, h_info *h);

    // add_com_str.c

    int add_com_str(s_42sh *sh, int i, h_info *h);

    // free_history.c

    void free_h(h_info *h);

#endif /* !HISTORY_FUNCTIONS_H_ */
