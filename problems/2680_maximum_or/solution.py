from typing import List


class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        n = len(nums)
        suffix = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] | nums[i]
        ans = 0
        prefix = 0
        for i in range(n):
            ans = max(ans, prefix | (nums[i] << k) | suffix[i + 1])
            prefix |= nums[i]
        return ans
