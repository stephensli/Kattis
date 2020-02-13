import os
import sys
from typing import List


# two built in functions, R -> Reverse, D -> DROP

def main():
    num_cases = int(sys.stdin.readline().strip())

    for case in range(num_cases):
        actions = list(sys.stdin.readline().strip())
        num_elements = int(sys.stdin.readline().strip())

        raw_array = sys.stdin.readline().strip()[1:]
        raw_array = raw_array[:len(raw_array) - 1]
        error = False

        array = None
        if raw_array == '':
            array = []
        else:
            array = raw_array.split(",")

        pop_back = False
        remove_count_font = 0
        remove_count_back = 0

        for idx, item in enumerate(actions):
            if item == "R":
                if remove_count_font + remove_count_back > len(array):
                    print("error")
                    error = True
                    break

                pop_back = not pop_back

            elif item == "D":
                if pop_back:
                    remove_count_back += 1
                elif not pop_back:
                    remove_count_font += 1

        if not error:
            if remove_count_font + remove_count_back > len(array):
                print("error")
                continue

            array = array[remove_count_font:len(array) - remove_count_back]

            if pop_back:
                array = list(reversed(array))
            joined = ",".join(array)
            print("[{}]".format(joined))


if __name__ == '__main__':
    main()
