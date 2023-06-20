# EPITECH PROJECT, 2022
# 105torus
# File description:
# newtons_method
#

from calc_funtion import *


def deriv_f_x(l_nb, x):
    return 4 * l_nb[4] * x**3 + 3 * l_nb[3] * x**2 + 2 * l_nb[2] * x + l_nb[1]


def newtons_method(list_nbr):
    x = 0.5
    list_sol = []
    old_value = 0
    i = 0
    while abs(x - old_value) > 10**(-list_nbr[5]) and i < 500:
        old_value = x
        list_sol.append(x)
        if deriv_f_x(list_nbr, x) == 0:
            exit(84)
        x -= (f_x(list_nbr, x) / deriv_f_x(list_nbr, x))
        i += 1
    if i == 500:
        exit(84)
    return list_sol
