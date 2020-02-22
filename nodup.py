import os
import sys


def main():
    source = sys.stdin.readline().strip().lower().split(" ")

    repeated_words = set()
    repeated = False

    for word in source:
        if word in repeated_words:
            repeated = True
            break

        repeated_words.add(word)

    if repeated:
        print("no")
    else:
        print("yes")


if __name__ == '__main__':
    main()
