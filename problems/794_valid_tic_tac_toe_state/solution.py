from typing import List


class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        x_count = sum(row.count('X') for row in board)
        o_count = sum(row.count('O') for row in board)
        def wins(player):
            for i in range(3):
                if all(board[i][j] == player for j in range(3)): return True
                if all(board[j][i] == player for j in range(3)): return True
            if all(board[i][i] == player for i in range(3)): return True
            if all(board[i][2-i] == player for i in range(3)): return True
            return False
        if o_count > x_count or x_count > o_count + 1:
            return False
        if wins('X') and o_count != x_count - 1:
            return False
        if wins('O') and x_count != o_count:
            return False
        return True
