#!/usr/bin/env python3\n##
# EPITECH PROJECT, 2022
# calcul_matrix
# File description:
# programmers start to count from 0
#


def calcul_float_matrix(matrix_key, matrix_msg):
    col = len(matrix_msg)
    size_matrix = len(matrix_key)
    matrix_res = [[0.0 for x in range(size_matrix)] for y in range(col)]
    final_matrix = [[' ' for x in range(size_matrix)] for y in range(col)]
    for y in range(col):
        for x in range(size_matrix):
            for i in range(size_matrix):
                matrix_res[y][x] += float(matrix_msg[y][i]) * matrix_key[i][x]
            final_matrix[y][x] = chr(round(matrix_res[y][x])) 
    return final_matrix


def calcul_matrix(matrix_key, matrix_msg, indic):
    if indic == '1':
        return calcul_float_matrix(matrix_key, matrix_msg)
    col = len(matrix_msg)
    size_matrix = len(matrix_key)
    matrix_res = [[0 for x in range(size_matrix)] for y in range(col)]
    for y in range(col):
        for x in range(size_matrix):
            for i in range(size_matrix):
                matrix_res[y][x] += matrix_msg[y][i] * matrix_key[i][x]
    return matrix_res
