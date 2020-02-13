import os
import sys


def main():
    first = list(sys.stdin.readline().strip())
    second = list(sys.stdin.readline().strip())

    if len(first) > len(second):
        for x in range(len(first) - len(second)):
            second.insert(0, '0')
    elif len(second) > len(first):
        for x in range(len(second) - len(first)):
            first.insert(0, '0')

    for idx, num in enumerate(first):
        num1, num2 = int(first[idx]), int(second[idx])

        if num1 > num2:
            second[idx] = -1
        elif num2 > num1:
            first[idx] = -1

    first = list(filter(lambda e: e != -1, first))
    second = list(filter(lambda e: e != -1, second))

    if len(first) > 0 and first[0] == '0':
        first = ["0"]
    if len(second) > 0 and second[0] == '0':
        second = ["0"]

    if len(first) == 0:
        print("YODA")
    else:
        print("".join(first))

    if len(second) == 0:
        print("YODA")
    else:
        print("".join(second))


if __name__ == '__main__':
    main()
