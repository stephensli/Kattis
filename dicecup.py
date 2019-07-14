import math


def solve():
    a, b = [int(s) for s in input().split(' ')]

    n = None
    m = None

    if (a > b):
        n = a
        m = b
    else:
        n = b
        m = a

    for i in range(m + 1, n + 2):
        print(i)


if __name__ == "__main__":
    solve()
