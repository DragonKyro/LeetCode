from typing import List


class NeighborSum:
    def __init__(self, grid: List[List[int]]):
        self.pos = {}
        self.grid = grid
        self.n = len(grid)
        for i in range(self.n):
            for j in range(self.n):
                self.pos[grid[i][j]] = (i, j)

    def adjacentSum(self, value: int) -> int:
        i, j = self.pos[value]
        s = 0
        for di, dj in [(-1,0),(1,0),(0,-1),(0,1)]:
            ni, nj = i+di, j+dj
            if 0 <= ni < self.n and 0 <= nj < self.n:
                s += self.grid[ni][nj]
        return s

    def diagonalSum(self, value: int) -> int:
        i, j = self.pos[value]
        s = 0
        for di, dj in [(-1,-1),(-1,1),(1,-1),(1,1)]:
            ni, nj = i+di, j+dj
            if 0 <= ni < self.n and 0 <= nj < self.n:
                s += self.grid[ni][nj]
        return s
