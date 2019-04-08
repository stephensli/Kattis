
bottoms = set()
tops = set()

points = []

for i in range(3):
    first, second = [value for value in input().split(' ')]
    points.append((first, second))

    bottoms.add(first)
    tops.add(second)

for bottom in bottoms:
    for top in tops:
        if (not (bottom, top) in points):
            print("{} {}".format(bottom, top))
            break
