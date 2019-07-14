import math

t = int(input())


def solve():
    cities = set()

    for i in range(int(input())):
        cities.add(input())

    return len(cities)


def main():
    for i in range(t):
        print("{}".format(solve()))


if __name__ == "__main__":
    main()
