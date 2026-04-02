from typing import List


class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        dp = [1] * (nums[0] + 1)
        for i in range(1, n):
            new_dp = [0] * (nums[i] + 1)
            prefix = 0
            k = 0
            for j in range(nums[i] + 1):
                bound = min(j, nums[i-1] - nums[i] + j)
                while k <= bound and k <= nums[i-1]:
                    prefix = (prefix + dp[k]) % MOD
                    k += 1
                new_dp[j] = prefix
            dp = new_dp
        return sum(dp) % MOD
