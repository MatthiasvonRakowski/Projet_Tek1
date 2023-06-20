# EPITECH PROJECT, 2022
# 105torus
# File description:
# bisection_method
#

from calc_funtion import *

def bisection_method(list_coeff):
    a = 0.0
    b = 1.0
    i = 0
    list_sol = []

    while abs(f_x(list_coeff, (a + b) / 2)) > 10**(-list_coeff[5]) and i < 500:
        if (a - b) / 2 == 0:
            list_sol.append((a + b) / 2)
            return list_sol
        list_sol.append((a + b) / 2)
        if f_x(list_coeff, a) * f_x(list_coeff, (a + b) / 2) < 0:
            b = (a + b) / 2
        else:
            a = (a + b) / 2
        i += 1
    list_sol.append((a + b) / 2)
    if i == 500:
        exit(84)
    return list_sol
