from typing import List


class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        for j in range(n):
            for i in range(m):
                if grid[i][j] != grid[0][j]:
                    return False
            if j + 1 < n and grid[0][j] == grid[0][j + 1]:
                return False
        return True
