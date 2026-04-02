from typing import List


class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        m = n // 2
        ops = 0
        for i in range(n):
            if i <= m and nums[i] > k:
                ops += nums[i] - k
            elif i >= m and nums[i] < k:
                ops += k - nums[i]
        return ops
