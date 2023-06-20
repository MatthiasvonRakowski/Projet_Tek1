/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** setenv_unsetenv_functions
*/

#ifndef SETENV_UNSETENV_FUNCTIONS_H_
    #define SETENV_UNSETENV_FUNCTIONS_H_

    #include "../../../include/struct_42sh.h"
    #include "../cd_functions/cd_functions.h"

    // setenv.c

    void setenv_functions(ast_node *node, com_info *com_info);

    //unsetenv.c

    void unsetenv_functions(ast_node *node, com_info *com_info);

    // check_alphanum_and_return_output

    void return_alphanum_output(ast_node *node, com_info *com_info);
    int check_alpha_num(ast_node *node);


#endif /* !SETENV_UNSETENV_FUNCTIONS_H_ */
