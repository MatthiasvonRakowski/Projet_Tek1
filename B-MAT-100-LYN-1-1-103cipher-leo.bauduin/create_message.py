# EPITECH PROJECT, 2022
# create_message
# File description:
# create the matrix of the message
#


import re


def create_msg_matrix(message: str, i, matrix) -> list:
    if i == '1':
        message = re.findall(r'\d+', message)
        message = list(map(int, message))

    size = len(message)
    size_matrix = len(matrix)
    col = 0
    if size % size_matrix == 0:
        col = int(size / int(size_matrix))
    else:
        col = (int(size / int(size_matrix)) + 1)
    matrix_msg = [[0 for x in range(size_matrix)] for y in range(col)]
    k = 0
    for y in range(col):
        for x in range(size_matrix):
            if k < size:
                if i == '1':
                    matrix_msg[y][x] = message[k]
                else:
                    matrix_msg[y][x] = ord(message[k])
                k += 1
            else:
                break
    return matrix_msg
