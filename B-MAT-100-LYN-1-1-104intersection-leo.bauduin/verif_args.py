# EPITECH PROJECT, 2022
# 104intersection
# File description:
# verif_args
#
import sys


def print_info():
    with open("info_project.txt", 'r') as files:
        files = files.readlines()
    for lines in files:
        print(lines, end='')


def verif_args(args) -> list:
    if len(args) != 2 and len(args) != 9:
        print("Retry with option -h")
        sys.exit(84)
    if args[1] == "-h" and len(args) == 2:
        print_info()
        sys.exit(0)
    if len(args) == 2:
        print("You don't have enough argument see how to use with option -h")
        sys.exit(84)
    for i in range(1, len(args)):
        try:
            args[i] = int(args[i])
        except ValueError:
            print("Value are not int, please fix it")
            print("For help try the option -h")
            sys.exit(84)
    if args[5] == 0 and args[6] == 0 and args[7] == 0:
        print("Vector director are invalid")
        sys.exit(84)
    return args
