from typing import List


class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        result = 0
        prefix_sum = 0
        for i in range(len(nums)):
            prefix_sum += nums[i]
            result = max(result, (prefix_sum + i) // (i + 1))
        return result
