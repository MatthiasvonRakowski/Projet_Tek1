from sys import argv


def display_model_evolution():
    gen_act = float(argv[1])
    grow_rate = float(argv[2])
    print("1 %.2f" % gen_act)
    i = 2
    while i <= 100:
        gen_act = (gen_act * grow_rate) * (1000 - gen_act) / 1000
        print("%d %.2f" % (i, gen_act))
        i = i + 1
