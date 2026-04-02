from typing import List


class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m, n = len(board), len(board[0])
        r, c = click
        if board[r][c] == 'M':
            board[r][c] = 'X'
            return board
        
        def dfs(i: int, j: int) -> None:
            mines = 0
            for di in range(-1, 2):
                for dj in range(-1, 2):
                    ni, nj = i + di, j + dj
                    if 0 <= ni < m and 0 <= nj < n and board[ni][nj] == 'M':
                        mines += 1
            if mines > 0:
                board[i][j] = str(mines)
            else:
                board[i][j] = 'B'
                for di in range(-1, 2):
                    for dj in range(-1, 2):
                        ni, nj = i + di, j + dj
                        if 0 <= ni < m and 0 <= nj < n and board[ni][nj] == 'E':
                            dfs(ni, nj)
        
        dfs(r, c)
        return board
