from typing import List


class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:
        n = len(nums)
        dp_pos = nums[0]
        dp_neg = float('-inf')
        for i in range(1, n):
            new_pos = max(dp_pos, dp_neg) + nums[i]
            new_neg = dp_pos - nums[i]
            dp_pos, dp_neg = new_pos, new_neg
        return max(dp_pos, dp_neg)
