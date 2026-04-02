from typing import List


class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        ans = 0
        for c in range(n - 2, -1, -1):
            for r in range(m):
                for dr in [-1, 0, 1]:
                    nr = r + dr
                    if 0 <= nr < m and grid[nr][c + 1] > grid[r][c]:
                        dp[r][c] = max(dp[r][c], 1 + dp[nr][c + 1])
        return max(dp[r][0] for r in range(m))
