/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include "../../include/struct_42sh.h"

    // store_command.c

    void store_dif_command(s_42sh *sh_42);

    // free_tree.c

    void free_tree(s_42sh *sh_42, com_info *com_info);

    //create_tree.c

    void create_tree(s_42sh *sh_42);
    void create_tree_next(ast_node *node, s_42sh *sh_42);
    void split_command(ast_node *node, int i, char *str, int check);
    int check_red(int i, char *str, int size);

    // str_to_word_array.c

    char **my_str_to_word_array(const char *str);

    // check_parentheses.c

    void check_parentheses(ast_node *node, s_42sh *sh_42);
    int move_next_par(int i, ast_node *node);

#endif /* !MY_H_ */
