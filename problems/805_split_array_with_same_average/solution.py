from typing import List


class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        n = len(nums)
        total = sum(nums)
        if n == 1:
            return False
        half = n // 2
        for k in range(1, half + 1):
            if total * k % n == 0:
                break
        else:
            return False
        dp = [set() for _ in range(half + 1)]
        dp[0].add(0)
        for num in nums:
            for k in range(half, 0, -1):
                for s in dp[k - 1]:
                    dp[k].add(s + num)
        for k in range(1, half + 1):
            if total * k % n == 0 and total * k // n in dp[k]:
                return True
        return False
