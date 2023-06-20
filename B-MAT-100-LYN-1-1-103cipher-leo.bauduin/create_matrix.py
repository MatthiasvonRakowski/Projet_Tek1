# EPITECH PROJECT, 2022
# create_matrix
# File description:
# create the good matrix
#


import math as ma


def create_key_matrix(key) -> list:
    size = len(key)
    size_matrix = int(ma.sqrt(size - 1) + 1)
    matrix_key = [[0 for x in range(size_matrix)] for y in range(size_matrix)]
    k = 0
    for y in range(size_matrix):
        for x in range(size_matrix):
            if k < size:
                matrix_key[y][x] = ord(key[k])
                k += 1
    return matrix_key
