from typing import List


class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        if sum(nums) < 2 * k:
            return 0
        dp = [0] * k
        dp[0] = 1
        for num in nums:
            for j in range(k - 1, num - 1, -1):
                dp[j] = (dp[j] + dp[j - num]) % MOD
        bad = sum(dp) * 2 % MOD
        total = pow(2, len(nums), MOD)
        return (total - bad) % MOD
