# EPITECH PROJECT, 2022
# 104intersection
# File description:
# calcul_mode
#
import sys
import math as ma


def one_sol(b, c, sol):
    sol.append(float(- (c / b)))


def two_sol(a, b, delta, sol):
    sol.append(float(-1 * b + delta) / (2 * a))
    sol.append(float(-1 * b - delta) / (2 * a))


def delt_check(a, b, c, sol):
    delta = b**2 - (4 * a * c)
    if delta < 0:
        print("No intersection point.")
        sys.exit(0)
    if 1e-5 >= delta >= -1e-5:
        return one_sol(2 * a, b, sol)
    return two_sol(a, b, float(ma.sqrt(delta)), sol)


def sol_math(a, b, c, sol):
    if 1e-5 >= a >= -1e-5 and 1e-5 >= b >= -1e-5 and 1e-5 >= c >= -1e-5:
        print("There is an infinite number of intersection points.")
        sys.exit(0)
    if 1e-5 >= a >= -1e-5 and 1e-5 >= b >= -1e-5:
        print("No intersection point.")
        sys.exit(0)
    if 1e-5 >= a >= -1e-5:
        return one_sol(b, c, sol)
    return delt_check(a, b, c, sol)
