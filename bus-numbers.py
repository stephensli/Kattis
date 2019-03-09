number_of_buses = int(input())

buses = input().split(' ')

for idx, val in enumerate(buses):
    buses[idx] = int(val)

buses.sort()
count = 0

for index, value in enumerate(buses):
    if ((index + 1) < len(buses) and buses[index + 1] == value + 1):
        count += 1

        if (count == 1):
            print(value, end="")
    elif (count >= 2):
        print("-{}".format(value), end=" ")
        count = 0;
    elif (count == 1):
        print("", value, end=" ")
        count = 0;
    else:
        print(value, end=" ")
        count = 0;
