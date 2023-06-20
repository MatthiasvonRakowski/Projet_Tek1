# EPITECH PROJECT, 2022
# 104intersection
# File description:
# 104intersection
#

def print_point_and_vector(pt, vt):
    print("Line passing through the point", end="")
    print(" (%d, %d, %d) and parallel to the vector (%d, %d, %d)" % (pt[0], pt[1],
                                                                     pt[2], vt[0],
                                                                     vt[1], vt[2]))


def print_solution(pt, vt, sol):
    if len(sol) >= 2:
        print("%d intersection points:" % len(sol))
    else:
        print("%d intersection point:" % len(sol))

    for j in range(len(sol)):
        nb = [0, 0, 0]
        for i in range(len(pt)):
            temp = float(pt[i] + vt[i] * sol[j])
            if 0 > temp >= -1e-3:
                temp *= -1
            nb[i] = temp
        print("(%.3f, %.3f, %.3f)" % (nb[0], nb[1], nb[2]))
