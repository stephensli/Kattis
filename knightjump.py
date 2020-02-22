import sys
import time

from collections import namedtuple
from typing import List

Move = namedtuple("Move", "can_move move row col")
Stage = namedtuple("Stage", "number move row col")


def follow_path(moves: List[Move], knight_x: int, knight_y: int):
    global visited

    if knight_x == 0 and knight_y == 0:
        return 0

    made_min = None
    stages = []

    for move in moves:
        stages.append(Stage(1, move, knight_x, knight_y))

    num_stages = len(stages)

    while num_stages != 0:
        n_stage: Stage = stages.pop()
        num_stages -= 1

        if made_min is not None and made_min <= n_stage.number:
            continue

        k_row, k_col = n_stage.move.move(n_stage.row, n_stage.col)

        if k_row == 0 and k_col == 0:
            if made_min is None or made_min > n_stage.number:
                made_min = n_stage.number
            continue

        allowed_moves = []

        for move in moves:
            if move.can_move(k_row, k_col) and "{} {}".format(move.row,
                                                              move.col) not in visited and move.row != -n_stage.move.row and move.col != n_stage.move.col:
                visited.append("{} {}".format(move.row, move.col))
                allowed_moves.append(move)

        for move in allowed_moves:
            stages.append(Stage(n_stage.number + 1, move, k_row, k_col))
            num_stages += 1

    if made_min is None:
        return -1

    return made_min


def generate_move(row, col):
    def can_move(knight_row, knight_col):
        global board
        global board_limit

        if knight_row + row < 0:
            return False
        if knight_row + row > board_limit - 1:
            return False

        if knight_col + col < 0:
            return False
        if knight_col + col > board_limit - 1:
            return False
        if "{} {}".format(knight_row + row, knight_col + col) in board:
            return False

        return True

    def move(knight_row, knight_col):
        return knight_row + row, knight_col + col

    return Move(can_move, move, row, col)


visited = []
board = []
board_limit = 0


def main():
    global board, board_limit

    board_limit = int(sys.stdin.readline().strip())
    # start_time = time.time()

    moves = [
        generate_move(2, 1),
        generate_move(1, 2),
        generate_move(-1, 2),
        generate_move(2, -1),
        generate_move(1, -2),
        generate_move(-2, 1),
        generate_move(-2, -1),
        generate_move(-1, -2),
    ]

    knight_row, knight_col = None, None

    for idx in range(board_limit):
        row = list(sys.stdin.readline().strip())

        if knight_row is None and "K" in row:
            knight_col = row.index("K")
            knight_row = idx

        for rowidx, item in enumerate(row):
            if item == "#":
                board.append("{} {}".format(idx, rowidx))

    # first filter out all the moves that are not possible from the first standpoint.
    # e.g have no meaningful value to use with the following attempts to shift.
    allowed_moves = list(filter(lambda e: e.can_move(knight_row, knight_col), moves))
    result = follow_path(allowed_moves, knight_row, knight_col)
    print(result)


# print("--- %s seconds ---" % (time.time() - start_time))


if __name__ == '__main__':
    main()
