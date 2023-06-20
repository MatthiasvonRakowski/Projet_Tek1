# EPITECH PROJECT, 2022
# inverse_matrix
# File description:
# inverse matrix
#
import sys


def divide_matrix_line(matrix_r: list[float], matrix_i: list[float], nb: float):
    for i in range(len(matrix_r)):
        matrix_r[i] /= nb
        matrix_i[i] /= nb


def fill_matrix_i(matrix_i):
    for line in range(len(matrix_i)):
        matrix_i[line][line] = 1


def inverse_matrix(matrix_r) -> list:
    len_m = len(matrix_r)
    matrix_i = [[0 for i in range(len_m)] for a in range(len_m)]
    fill_matrix_i(matrix_i)
    for pos in range(len_m):
        pivot = matrix_r[pos][pos]
        if pivot == 0:
            sys.exit(84)
        divide_matrix_line(matrix_r[pos], matrix_i[pos], pivot)
        calc_line = matrix_r[pos]
        for line in range(len_m):
            if line == pos:
                continue
            line_mult = float(matrix_r[line][pos])
            for num in range(len(matrix_r[line])):
                matrix_r[line][num] -= line_mult * calc_line[num]
                matrix_i[line][num] -= line_mult * matrix_i[pos][num]
    return matrix_i
