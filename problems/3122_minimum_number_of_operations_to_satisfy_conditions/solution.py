from typing import List


class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        freq = [[0] * 10 for _ in range(n)]
        for i in range(m):
            for j in range(n):
                freq[j][grid[i][j]] += 1
        dp = [[float('inf')] * 10 for _ in range(n)]
        for d in range(10):
            dp[0][d] = m - freq[0][d]
        for j in range(1, n):
            for d in range(10):
                cost = m - freq[j][d]
                for pd in range(10):
                    if pd != d:
                        dp[j][d] = min(dp[j][d], dp[j-1][pd] + cost)
        return min(dp[n-1])
