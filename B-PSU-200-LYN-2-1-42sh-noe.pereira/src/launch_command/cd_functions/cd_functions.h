/*
** EPITECH PROJECT, 2023
** Shell-Programming
** File description:
** cd_functions
*/

#ifndef CD_FUNCTIONS_H_
    #define CD_FUNCTIONS_H_

    #include "../../../include/struct_42sh.h"

    // cd_functions.c

    void cd_funct(ast_node *root, com_info *com_info);
    int check_cd(ast_node *root, com_info *com_info);

    // change_path.c

    void change_current_pwd(com_info *com_info);
    void change_old_path(com_info *com_info);

    // check_error.c

    void check_error_cd(com_info *com_info, ast_node *node);

    // ressource.c

    int my_compare_str(char const *s1, char const *s2, int n);
    int size_env_line(char *str);
    void my_copy(char *str, char *str1, char *str2);


#endif /* !CD_FUNCTIONS_H_ */
