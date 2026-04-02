from typing import List


class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row = [sum(grid[i]) for i in range(m)]
        col = [sum(grid[i][j] for i in range(m)) for j in range(n)]
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    res += (row[i] - 1) * (col[j] - 1)
        return res
