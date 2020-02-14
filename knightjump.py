import os
import sys
import time

from collections import namedtuple
from typing import List

Move = namedtuple("Move", "can_move move row col")
Stage = namedtuple("Stage", "number board move row col")


def follow_path(moves: List[Move], board: List[List[str]], knightx: int, knighty: int):
    # first filter out all the moves that are not possible from the first standpoint.
    # e.g have no meaningful value to use with the following attempts to shift.
    allowed_moves = list(filter(lambda e: e.can_move(board, knightx, knighty), moves))

    stages = []
    made_mid = []
    made_mid_min = None

    for move in allowed_moves:
        stages.append(Stage(1, board, move, knightx, knighty))

    while len(stages) != 0:
        next_stage: Stage = stages.pop()

        if len(made_mid) > 0 and made_mid_min <= next_stage.number:
            continue

        nboard, krow, kcol = next_stage.move.move(next_stage.board, next_stage.row, next_stage.col)

        if krow == 0 and kcol == 0:
            made_mid.append(next_stage.number)
            made_mid_min = min(made_mid)

            new_stages = []
            for stage in stages:
                if made_mid_min > stage.number:
                    new_stages.append(stage)

            stages = new_stages
            continue

        allowed_moves = []

        for move in moves:
            if move.can_move(nboard, krow,
                             kcol) and move.row != -next_stage.move.row and move.col != next_stage.move.col:
                allowed_moves.append(move)

        for move in allowed_moves:
            stages.append(Stage(next_stage.number + 1, nboard, move, krow, kcol))

    if len(made_mid) == 0:
        return -1
    return min(made_mid)


def generate_move(row, col):
    def can_move(board, knight_row, knight_col):
        if knight_row + row < 0:
            return False
        if knight_row + row > len(board) - 1:
            return False

        if knight_col + col < 0:
            return False
        if knight_col + col > len(board[knight_row]) - 1:
            return False
        if board[knight_row + row][knight_col + col] == "#":
            return False

        return True

    def move(board, knight_row, knight_col):
        board[knight_row][knight_col] = "."

        board[knight_row + row][knight_col + col] = "K"
        return board, knight_row + row, knight_col + col

    return Move(can_move, move, row, col)


def main():
    start_time = time.time()
    rows_columns = int(sys.stdin.readline().strip())
    board = [[]] * rows_columns

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

    for idx in range(rows_columns):
        board[idx] = list(sys.stdin.readline().strip())

        if knight_row is None and "K" in board[idx]:
            knight_col = board[idx].index("K")
            knight_row = idx

    if knight_col == 0 and knight_row == 0:
        print(0)
    else:
        result = follow_path(moves, board, knight_row, knight_col)
        print(result)

    print("--- %s seconds ---" % (time.time() - start_time))


if __name__ == '__main__':
    main()
