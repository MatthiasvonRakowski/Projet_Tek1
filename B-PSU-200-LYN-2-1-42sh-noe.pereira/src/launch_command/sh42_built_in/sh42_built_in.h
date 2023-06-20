/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-noe.pereira
** File description:
** sh42_built_in
*/

#pragma once

#include "../../../include/sh42_include.h"

// where_function.h

void where_function(ast_node *root, com_info *com_info);

// alias.c

void alias_function(ast_node *root, com_info *com_info);
void unalias_function(ast_node *root, com_info *com_info);

// which_function.c

void which_function(ast_node *root, com_info *com_info);
