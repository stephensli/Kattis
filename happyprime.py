import os
import sys
import math

primes = {}
happy = {}


def is_prime(num):
    if num == 1:
        return False
    if num == 2:
        return True

    for i in range(2, int(math.sqrt(num))):
        if num % i == 0:
            return False

    return True


def solve(number):
    if number in primes and primes[number]:
        return happy[number]

    s = 0
    nn = number

    while nn >= 1:
        s += (nn % 10) * (nn % 10)
        nn /= 10

    if s == 1:
        primes[number] = True
        happy[number] = True
        return True

    primes[number] = True
    temp = solve(s)

    happy[number] = temp
    return temp


def main():
    number_cases = int(sys.stdin.readline().strip())

    primes[1] = True
    happy[1] = True

    for num in range(number_cases):
        first, second = sys.stdin.readline().strip().split(" ")
        first, second = int(first), int(second)

        if solve(second) and is_prime(second):
            print("{} {} YES".format(first, second))
        else:
            print("{} {} NO".format(first, second))


if __name__ == '__main__':
    main()
