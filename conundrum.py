import math

# t = int(input())


def solve():
    value = input()
    count = 0

    for i in range(0, len(value)):
        if (value[i % (len(value))] != 'PER'[i % 3]):
            count += 1

    return count


# for i in range(t):
print("{}\n".format(solve()))
