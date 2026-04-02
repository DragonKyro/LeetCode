from typing import List


class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        pos = [None] * (n * n)
        for r in range(n):
            for c in range(n):
                pos[grid[r][c]] = (r, c)
        if pos[0] != (0, 0): return False
        for i in range(1, n * n):
            r1, c1 = pos[i - 1]
            r2, c2 = pos[i]
            dr, dc = abs(r1-r2), abs(c1-c2)
            if not ((dr == 1 and dc == 2) or (dr == 2 and dc == 1)):
                return False
        return True
