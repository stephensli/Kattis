import math
from datetime import datetime

# t = int(input())

days = ['Monday', 'Tuesday', 'Wednesday',
        'Thursday', 'Friday', 'Saturday', 'Sunday']


def solve():
    day, month = [int(i) for i in input().split(' ')]

    date = datetime.now()
    date = date.replace(year=2009, month=month, day=day)

    global days
    return days[date.weekday()]


# for i in range(t):
print("{}\n".format(solve()))
