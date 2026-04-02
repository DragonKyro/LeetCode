from typing import List


class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        dp = [1, 0, 1]
        for i in range(1, len(obstacles)):
            for j in range(3):
                if obstacles[i] == j + 1:
                    dp[j] = float('inf')
            for j in range(3):
                if obstacles[i] != j + 1:
                    for k in range(3):
                        if k != j and obstacles[i] != k + 1:
                            dp[j] = min(dp[j], dp[k] + 1)
        return min(dp)
