from typing import List


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        result = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(n - 2):
            for j in range(n - 2):
                mx = 0
                for di in range(3):
                    for dj in range(3):
                        mx = max(mx, grid[i + di][j + dj])
                result[i][j] = mx
        return result
