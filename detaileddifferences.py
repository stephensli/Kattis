import math

t = int(input())


def solve():
    first = input()
    second = input()

    result = [first, '\n', second, '\n']

    for i in range(len(first)):
        if (first[i] == second[i]):
            result.append('.')
        else:
            result.append('*')

    return ''.join(result)


for i in range(t):
    print("{}\n".format(solve()))
