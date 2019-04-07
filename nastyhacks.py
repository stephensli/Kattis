import math

t = int(input())


def solve():
    r, e, c = [int(s) for s in input().split(' ')]

    if ((e - c) > r):
        return "advertise"
    elif ((e - c) == r):
        return "does not matter"
    else:
        return "do not advertise"


def main():
    for i in range(t):
        print("{}".format(solve()))


if __name__ == "__main__":
    main()
