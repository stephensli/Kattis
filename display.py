import sys

# top, left, middle, bottom, right
spacer = [' ', ' ', 'o', ' ', 'o', ' ', ' ']

zero = ['+---+', '|   |', '|   |', '+   +', '|   |', '|   |', '+---+']
one = ['    +', '    |', '    |', '    +', '    |', '    |', '    +']
two = ['+---+', '    |', '    |', '+---+', '|    ', '|    ', '+---+']
three = ['+---+', '    |', '    |', '+---+', '    |', '    |', '+---+']
four = ['+   +', '|   |', '|   |', '+---+', '    |', '    |', '    +']
five = ['+---+', '|    ', '|    ', '+---+', '    |', '    |', '+---+']
six = ['+---+', '|    ', '|    ', '+---+', '|   |', '|   |', '+---+']
seven = ['+---+', '    |', '    |', '    +', '    |', '    |', '    +']
eight = ['+---+', '|   |', '|   |', '+---+', '|   |', '|   |', '+---+']
nine = ['+---+', '|   |', '|   |', '+---+', '    |', '    |', '+---+']

numbers = {
    '0': zero,
    '1': one,
    '2': two,
    '3': three,
    '4': four,
    '5': five,
    '6': six,
    '7': seven,
    '8': eight,
    '9': nine,
}


def main(input_value):
    inputs = input_value.split(":")

    input = []
    sequences = [[], [], [], [], [], [], []]

    for idx, section in enumerate(inputs):
        first, second = list(section)

        input.append(numbers[first])
        input.append(numbers[second])

        if idx == 0:
            input.append(spacer)

    for idx in range(7):
        for letter in input:
            sequences[idx].append(letter[idx])

    for idx, sequence in enumerate(sequences):
        print("  ".join(sequence))


if __name__ == '__main__':
    while True:
        input_number = sys.stdin.readline().strip()

        if input_number == "end":
            print("end")
            break

        main(input_number)
        print("\n")
