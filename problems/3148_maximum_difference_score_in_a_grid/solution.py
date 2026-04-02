from typing import List


class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = float('-inf')
        mn = [[float('inf')] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i > 0: mn[i][j] = min(mn[i][j], mn[i-1][j])
                if j > 0: mn[i][j] = min(mn[i][j], mn[i][j-1])
                res = max(res, grid[i][j] - mn[i][j])
                mn[i][j] = min(mn[i][j], grid[i][j])
        return res
