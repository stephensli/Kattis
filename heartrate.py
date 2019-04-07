import math

t = int(input())


def solve():
    bBeats, pSeconds = [float(s) for s in input().split(' ')]

    ABPM = 60 / pSeconds
    BMP = (60 * bBeats) / pSeconds

    output = [BMP - ABPM, BMP, BMP + ABPM]

    return ' '.join("{0:.4f}".format(x) for x in output)


def main():
    for i in range(t):
        print("{}".format(solve()))


if __name__ == "__main__":
    main()
