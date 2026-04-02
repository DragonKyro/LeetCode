from typing import List


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    rx, ry = i, j
                    break
        result = 0
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            x, y = rx + dx, ry + dy
            while 0 <= x < 8 and 0 <= y < 8:
                if board[x][y] == 'B':
                    break
                if board[x][y] == 'p':
                    result += 1
                    break
                x += dx
                y += dy
        return result
