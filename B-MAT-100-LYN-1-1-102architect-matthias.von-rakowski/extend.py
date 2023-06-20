import math as m


def matrix_mul(matrix, matrix_transform):
    matrix_result = [[0, 0, 0],
                     [0, 0, 0],
                     [0, 0, 0]]
    for i in range(0, 3):
        for j in range(0, 3):
            matrix_result[i][j] = matrix[i][0] * matrix_transform[0][j] + matrix[i][1] * matrix_transform[1][j] + matrix[i][2] * matrix_transform[2][j]
    return matrix_result


def get_matrix_rotation(str_angle, matrix):
    angle = float(str_angle) * m.pi / 180
    matrix_reflection = [[m.cos(angle), -m.sin(angle), 0],
                         [m.sin(angle), m.cos(angle), 0],
                         [0, 0, 1]]
    return matrix_mul(matrix, matrix_reflection)


def get_matrix_reflection(str_angle, matrix):
    angle = float(str_angle) * m.pi / 180
    matrix_reflection = [[m.cos(2 * angle), m.sin(2 * angle), 0],
                         [m.sin(2 * angle), -m.cos(2 * angle), 0],
                         [0, 0, 1]]
    return matrix_mul(matrix, matrix_reflection)


def get_matrix_scale(str_scale_x, str_scale_y, matrix):
    scale_x = float(str_scale_x)
    scale_y = float(str_scale_y)
    matrix_scale = [[scale_x, 0, 0],
                    [0, scale_y, 0],
                    [0, 0, 1]]
    return matrix_mul(matrix, matrix_scale)


def get_matrix_translation(str_x, str_y, matrix):
    x = float(str_x)
    y = float(str_y)
    matrix_translation = [[1, 0, x],
                          [0, 1, y],
                          [0, 0, 1]]
    return matrix_mul(matrix, matrix_translation)
