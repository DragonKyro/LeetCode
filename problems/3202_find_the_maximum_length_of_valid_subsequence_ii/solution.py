from typing import List


class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        res = 0
        for c in range(k):
            dp = [0] * k
            for x in nums:
                r = x % k
                need = (c - r) % k
                dp[r] = dp[need] + 1
                res = max(res, dp[r])
        return res
