import os
import sys

from collections import namedtuple
from typing import List

Move = namedtuple("Move", "can_move move row col")


def contains_move_by_pos_and_remove(moves: List[Move], row, col):
    for move in moves:
        if move.row == row and move.col == col:
            moves.remove(move)
            return moves
    return moves


def follow_path(moves: List[Move], last_move: Move, board: List[List[str]], knightx: int, knighty: int, count: int):
    if knightx == 0 and knighty == 0:
        return count

    # first filter out all the moves that are not possible from the first standpoint.
    # e.g have no meaningful value to use with the following attempts to shift.
    allowed_moves = list(filter(lambda e: e.can_move(board, knightx, knighty), moves))

    # remove the reverse of a given move.
    if last_move is not None:
        allowed_moves = contains_move_by_pos_and_remove(allowed_moves, -last_move.row, -last_move.col)

    if len(allowed_moves) == 0:
        return count

    # Generate tree, in each section, branch off to follow that path until it reaches 0,0 or dies.
    # if it dies, cut it, otherwise continue until all checks are done. and then determine the min
    # tree length
    return count


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
             generate_move(-1, 2), generate_move(-1, -2)]

    for idx in range(rows_columns):
        board[idx] = list(sys.stdin.readline().strip())

    print(board)
    result = follow_path(moves, None, board, 0, 2, 0)
    if result == 0:
        print(-1)
    else:
        print(result)

    return


if __name__ == '__main__':
    main()
