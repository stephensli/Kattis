import math


def solve():
    x, y, z = [int(s) for s in input().split(' ')]

    for i in range(1, z + 1):
        if (i % x == 0 and i % y == 0):
            print("FizzBuzz")
        elif (i % x == 0):
            print("Fizz")
        elif (i % y == 0):
            print("Buzz")
        else:
            print(i)


def main():
    solve()


if __name__ == "__main__":
    main()
