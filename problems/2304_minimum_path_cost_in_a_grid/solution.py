from typing import List


class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [row[:] for row in [grid[0]]]
        dp = grid[0][:]
        for i in range(1, m):
            new_dp = [float('inf')] * n
            for j in range(n):
                for k in range(n):
                    new_dp[j] = min(new_dp[j], dp[k] + moveCost[grid[i-1][k]][j] + grid[i][j])
            dp = new_dp
        return min(dp)
