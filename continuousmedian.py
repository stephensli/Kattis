import math
import sys


def main():
    tests = int(sys.stdin.readline().strip())

    for test in range(tests):
        first = int(sys.stdin.readline().strip())
        second = [int(x) for x in sys.stdin.readline().strip().split(" ")]
        second.sort()

        if first == 0:
            continue

        total = 0

        median = 0
        for i in range(first):
            r = int(second[i])

            if second[0] < r < second[1]:
                # Move all right
                second[2] = second[1]
                second[1] = second[0]
                second[0] = r
            if second[1] < r < second[2]:
                # Move all left
                second[0] = second[1]

                second[1] = second[2]

                second[2] = r
            if (i + 1) % 2 == 0:
                # Median is average of two second elements
                median = math.floor((second[1] + second[2]) / 2)
            else:
                # Median is second element
                median = second[1]
                # Get new value
            print(median)

            total += median

        print(total)

    return


if __name__ == '__main__':
    main()
