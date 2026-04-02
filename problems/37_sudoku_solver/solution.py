from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for c in '123456789':
                            if is_valid(i, j, c):
                                board[i][j] = c
                                if solve():
                                    return True
                                board[i][j] = '.'
                        return False
            return True
        def is_valid(r, c, ch):
            for i in range(9):
                if board[r][i] == ch:
                    return False
                if board[i][c] == ch:
                    return False
                if board[3*(r//3)+i//3][3*(c//3)+i%3] == ch:
                    return False
            return True
        solve()
