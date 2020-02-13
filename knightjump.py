import os
import sys

from collections import namedtuple
from typing import List

Move = namedtuple("Move", "can_move move row col")
Stage = namedtuple("Stage", "number board move row col")


def contains_move_by_pos_and_remove(moves: List[Move], row, col):
    for move in moves:
        if move.row == row and move.col == col:
            moves.remove(move)
            return moves
    return moves


def follow_path(moves: List[Move], board: List[List[str]], knightx: int, knighty: int):
    if knightx == 0 and knighty == 0:
        return 0

    # first filter out all the moves that are not possible from the first standpoint.
    # e.g have no meaningful value to use with the following attempts to shift.
    allowed_moves = list(filter(lambda e: e.can_move(board, knightx, knighty), moves))
    stages = []
    made_mid = []

    for move in allowed_moves:
        stages.append(Stage(1, board, move, knightx, knighty))

    while len(stages) != 0:
        next_stage: Stage = stages.pop()

        if len(made_mid) > 0:
            if min(made_mid) <= next_stage.number:
                continue

        nboard, krow, kcol = next_stage.move.move(next_stage.board, next_stage.row, next_stage.col)

        if krow == 0 and kcol == 0:
            made_mid.append(next_stage.number)
            continue

        allowed_moves = list(filter(lambda e: e.can_move(nboard, krow, kcol), moves))
        allowed_moves = contains_move_by_pos_and_remove(allowed_moves, -next_stage.move.row, -next_stage.move.col)

        if len(allowed_moves) == 0:
            continue

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
    rows_columns = int(sys.stdin.readline().strip())
    board = [[]] * rows_columns

    moves = [generate_move(2, 1), generate_move(2, -1), generate_move(-2, 1),
             generate_move(-2, -1), generate_move(1, 2), generate_move(1, -2),
             generate_move(-1, 2), generate_move(-1, -2)
    for idx in range(rows_columns):
        board[idx] = list(sys.stdin.readline().strip())

    result = follow_path(moves, board, 0, 2)
    print(result)


if __name__ == '__main__':
    main()
