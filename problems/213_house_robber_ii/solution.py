from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        def rob_range(lo, hi):
            prev, curr = 0, 0
            for i in range(lo, hi):
                prev, curr = curr, max(curr, prev + nums[i])
            return curr
        return max(rob_range(0, len(nums) - 1), rob_range(1, len(nums)))
