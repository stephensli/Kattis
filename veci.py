import os
import sys

from itertools import permutations


def main():
    raw_number = sys.stdin.readline().strip()
    number = int(raw_number)

    largest = []

    for idx, com in enumerate(permutations(raw_number, len(raw_number))):
        if idx == 0:
            continue

        largest.append(int("".join(com)))

    largest_min_list = list(filter(lambda x: x > number, largest))

    if len(largest_min_list) == 0:
        print(0)
    else:
        print(min(largest_min_list))


if __name__ == '__main__':
    main()
