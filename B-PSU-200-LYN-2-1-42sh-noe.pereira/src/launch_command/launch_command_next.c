/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** launch_command_next
*/
#include "../../include/sh42_include.h"

int execute_buoilt_next(ast_node *root, com_info *com_info,
h_info *history, s_42sh *sh)
{
    if (com_info->unalias == 1) { com_info->unalias = 0;
        unalias_function(root, com_info); return (1);
    }
    return (0);
}

int execute_build(ast_node *root, com_info *com_info,
h_info *history, s_42sh *sh)
{
    if (com_info->cd == 1) { com_info->cd = 0;
        cd_funct(root, com_info); return (1);
    }
    if (com_info->setenv == 1) { com_info->setenv = 0;
        setenv_functions(root, com_info); return (1);
    }
    if (com_info->unsetenv == 1) { com_info->unsetenv = 0;
        unsetenv_functions(root, com_info); return (1);
    }
    if (com_info->history == 1) { com_info->history = 0;
        history_functions(root, history); return (1);
    }
    if (com_info->alias) { com_info->alias = 0;
        alias_function(root, com_info); return 1;
    }
    if (com_info->which) { com_info->which = 0;
        which_function(root, com_info); return 1;
    }
    return (execute_buoilt_next(root, com_info, history, sh));
}
