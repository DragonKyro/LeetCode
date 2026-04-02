from typing import List


class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        r1, r2, c1, c2 = m, 0, n, 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    r1 = min(r1, i)
                    r2 = max(r2, i)
                    c1 = min(c1, j)
                    c2 = max(c2, j)
        return (r2 - r1 + 1) * (c2 - c1 + 1)
