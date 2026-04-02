from typing import List


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        count = 0
        for i in range(n):
            for j in range(n):
                if all(grid[i][k] == grid[k][j] for k in range(n)):
                    count += 1
        return count
