from typing import List

import os
import sys
import math

primes = []
can_divide_by_prime_list = {}
points = {}


def get_next_player(player):
    if player == "O":
        return "E"
    if player == "E":
        return "I"
    if player == "I":
        return "O"


def is_prime(n):
    if n == 2 or n == 3: return True
    if n < 2 or n % 2 == 0: return False
    if n < 9: return True
    if n % 3 == 0: return False
    r = int(n ** 0.5)
    f = 5
    while f <= r:
        if n % f == 0: return False
        if n % (f + 2) == 0: return False
        f += 6
    return True


def generate_primes(top):
    for i in range(top):
        if is_prime(i):
            primes.append(i)


def can_divide_by_prime(number):
    if number in can_divide_by_prime_list:
        return can_divide_by_prime_list[number]

    current = None

    for prime in primes:
        if prime > number:
            break

        if number % prime == 0:
            result = int(number / prime)

            if current is None:
                current = [True, result]
                break
            else:
                if result < current[1]:
                    current[1] = result

    if current is None:
        can_divide_by_prime_list[number] = [False, None]
    else:
        can_divide_by_prime_list[number] = current

    return can_divide_by_prime_list[number]


def assign_to_all_points(people: List[str], amount: int):
    for p in people:
        if p in points:
            points[p] += amount
        else:
            points[p] = amount


def add_point_to_person(p: str, amount: int):
    if p in points:
        points[p] += amount
    else:
        points[p] = amount


def solve(starting_players: List[str], starting_numbers: List[int]) -> (int, int, int):
    players = ["O", "E", "I"]

    for idx, starting_player in enumerate(starting_players):
        start_number = starting_numbers[idx]
        if start_number == 1:
            assign_to_all_points(["O", "E", "I"], 1)
            continue

        final_score = start_number
        player = starting_player
        local_points = {"O": [], "E": [], "I": []}

        while final_score != 1:
            divide_or_add, returned = can_divide_by_prime(final_score)
            if divide_or_add:
                final_score = returned
            else:
                final_score += 1

            local_points[player].append(final_score)

            # Update the player to the following player after the round.
            print(player)
            player = get_next_player(player)

        for p in players:
            if len(local_points[p]) == 0:
                local_points[p].append(start_number)

        add_point_to_person("O", min(local_points["O"]))
        add_point_to_person("E", min(local_points["E"]))
        add_point_to_person("I", min(local_points["I"]))

        print(player)

    return "{} {} {}".format(points["O"], points["E"], points["I"])


def main():
    tests = int(sys.stdin.readline().strip())

    players = []
    numbers = []

    assign_to_all_points(["O", "E", "I"], 0)

    for test in range(tests):
        letter, number = sys.stdin.readline().strip().split(" ")
        number = int(number)

        players.append(letter)
        numbers.append(number)

    generate_primes(int(max(numbers) * 3))
    print(solve(players, numbers))


if __name__ == '__main__':
    main()
