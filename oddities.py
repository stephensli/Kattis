import math

t = int(input())


def solve():
    n = int(input())

    if (n % 2 == 0):
        return "{} is even".format(n)
    else:
        return "{} is odd".format(n)


def main():
    for i in range(t):
        print("{}".format(solve()))


if __name__ == "__main__":
    main()
