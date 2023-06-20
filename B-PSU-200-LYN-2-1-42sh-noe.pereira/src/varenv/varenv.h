/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** varenv
*/

#ifndef VARENV_H_
    #define VARENV_H_

    int detect_varenv(s_42sh *sh_42, com_info *com_info, h_info *history);

    char *replace_var(char *env, char *str, char *word);

    int detect_alias(char **str, com_info *com_info);

#endif /* !VARENV_H_ */
