import random
import math
import subprocess

verbose = False

def run_test(args):
    global verbose
    call = ["build/cl_triangle"] + args

    if verbose:
        print(args, end="\t")

    output = subprocess.check_output(call)
    print(output.decode()[:-2])


def main():

    print("# testing progressively larger random valid triangles...")
    test_cycles = 256
    for i in range(10, test_cycles):

        x1 = random.randint(-2**i, 0)
        y1 = random.randint(-2**i, 0)

        x2 = random.randint(1, 2**i)
        y2 = random.randint(-2**i, 0)

        x3 = random.randint(-2**i, 2**i)
        y3 = random.randint(1, 2**i)

        a = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
        b = math.sqrt((x2 - x3)**2 + (y2 - y3)**2)
        c = math.sqrt((x3 - x1)**2 + (y3 - y1)**2)

        run_test([f"{a}", f"{b}", f"{c}"])

    print("# testing progressively smaller random valid triangles...")
    test_cycles = 256
    for i in range(10, test_cycles):

        div = 2**i

        x1 = random.randint(-100, 0) / div
        y1 = random.randint(-100, 0) / div

        x2 = random.randint(1, 100) / div
        y2 = random.randint(-100, 0) / div

        x3 = random.randint(-100, 100) / div
        y3 = random.randint(1, 100) / div

        a = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
        b = math.sqrt((x2 - x3)**2 + (y2 - y3)**2)
        c = math.sqrt((x3 - x1)**2 + (y3 - y1)**2)

        run_test([f"{a}", f"{b}", f"{c}"])

    print("# testing various number representations")
    run_test(["0xA", "0xB", "0xC"])
    run_test(["0b0011", "0b0100", "0b0101"])
    run_test(["3", "4", "5"])
    run_test(["3.0", "4.0", "5.0"])
    run_test([".3", ".4", ".5"])
    run_test(["3.0e+1", "4.0e+1", "5.0e+1"])
    run_test(["3.0e-1", "4.0e-1", "5.0e-1"])

    print("# testing invalid arguments...")
    run_test(["foo", "4", "5"])
    run_test(["3", "bar", "4"])
    run_test(["foo", "bar", "4"])
    run_test(["3", "4", "baz"])
    run_test(["foo", "4", "baz"])
    run_test(["3", "bar", "baz"])
    run_test(["foo", "bar", "baz"])

    print("# testing missing arguments...")
    run_test([])
    run_test(["3"])
    run_test(["3", "4"])

    print("# testing invalid triangles...")
    run_test(["1", "2", "3"])
    run_test(["0", "0", "0"])
    run_test(["3", "0", "0"])
    run_test(["3", "3", "0"])


if __name__ == "__main__":
    main()
