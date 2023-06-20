from sys import argv


def calc_n_i0(n_gen1, i0, k):
    gen_act = n_gen1
    i = 1
    while i <= i0:
        gen_act = (gen_act * k) * (1000 - gen_act) / 1000
        i = i + 1
    return gen_act


def print_gens_k(n_gen1, i0, i1, k):
    n_i0 = calc_n_i0(n_gen1, i0, k)
    i = 1
    print("%.2f %.2f" % (k, n_i0))
    while i <= i1 - i0:
        n_i0 = (n_i0 * k) * (1000 - n_i0) / 1000
        print("%.2f %.2f" % (k, n_i0))
        i = i + 1


def display_every_possibilities():
    n_gen1 = int(argv[1])
    i0 = int(argv[2])
    i1 = int(argv[3])
    k = 1.00
    while k <= 4:
        print_gens_k(n_gen1, i0, i1, k)
        k = k + 0.01
