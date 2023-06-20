# EPITECH PROJECT, 2022
# 105torus
# File description:
# main
#

import sys


def check_error_args(argv):
    if len(argv) != 8:
        print("You don't have the good number of args, retry with option -h.")
        sys.exit(84)

    if int(argv[1]) > 3 or int(argv[1]) < 1:
        print("Option must be 1, 2 or 3, retry with the option -h.")
        sys.exit(84)

    if int(argv[7]) <= 0:
        print("The precision must be positive !")
        sys.exit(84)
    try:
        for i in range(1, len(argv)):
            argv[i - 1] = int(argv[i])
    except ValueError:
        print("You arguments must be number not string, retry with option -h.")
        sys.exit(84)
    del argv[7]
