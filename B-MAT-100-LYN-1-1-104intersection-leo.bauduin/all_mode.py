# EPITECH PROJECT, 2022
# 104intersection
# File description:
# 104intersection
#
from calcul_mode import *


def mode_sphere(pt, vt, radius, sol):
    a = vt[0]**2 + vt[1]**2 + vt[2]**2
    b = 2 * (pt[0]*vt[0] + pt[1]*vt[1] + pt[2]*vt[2])
    c = pt[0]**2 + pt[1]**2 + pt[2]**2 - radius
    sol_math(a, b, c, sol)


def mode_cylinder(pt, vt, radius, sol):
    a = vt[0]**2 + vt[1]**2
    b = 2 * (pt[0]*vt[0] + pt[1]*vt[1])
    c = pt[0]**2 + pt[1]**2 - radius
    sol_math(a, b, c, sol)


def mode_cone(pt, vt, radius, sol):
    a = vt[0]**2 + vt[1]**2 - vt[2]**2 * radius
    b = 2 * (pt[0]*vt[0] + pt[1]*vt[1] - pt[2]*vt[2] * radius)
    c = pt[0]**2 + pt[1]**2 - pt[2]**2 * radius
    sol_math(a, b, c, sol)
