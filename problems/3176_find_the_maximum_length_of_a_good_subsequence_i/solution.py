from typing import List


class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [[0] * (k + 1) for _ in range(n)]
        res = 1
        for i in range(n):
            for j in range(k + 1):
                dp[i][j] = 1
                for p in range(i):
                    if nums[p] == nums[i]:
                        dp[i][j] = max(dp[i][j], dp[p][j] + 1)
                    elif j > 0:
                        dp[i][j] = max(dp[i][j], dp[p][j - 1] + 1)
                res = max(res, dp[i][j])
        return res
