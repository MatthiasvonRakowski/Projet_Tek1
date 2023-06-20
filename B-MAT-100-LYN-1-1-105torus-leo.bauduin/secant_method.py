# EPITECH PROJECT, 2022
# 105torus
# File description:
# secant_method
#

from calc_funtion import *


def secant_method(list_coeff):
    a = 0.0
    b = 1.0
    x = 1.0
    i = 0
    list_sol = []
    while abs(f_x(list_coeff, x)) > 10**-list_coeff[5] and i < 500:
        if abs(f_x(list_coeff, b) - f_x(list_coeff, a)) == 0:
            exit(84)
        x = b - f_x(list_coeff, b) * (b - a) / (f_x(list_coeff, b) - f_x(list_coeff, a))
        a = b
        b = x
        list_sol.append(x)
        i += 1
    if i == 500:
        exit(84)
    return list_sol
