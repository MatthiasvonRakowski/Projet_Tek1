/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** redirection
*/

#ifndef REDIRECTION_H_
    #define REDIRECTION_H_

    #include "../../include/struct_42sh.h"

    void launch_redirection_r(ast_node *l_son, ast_node *r_son,
    com_info *com_info, bool trunc);

    void launch_redirection_l(ast_node *l_son, ast_node *r_son,
    com_info *com_info);

#endif /* !REDIRECTION_H_ */
