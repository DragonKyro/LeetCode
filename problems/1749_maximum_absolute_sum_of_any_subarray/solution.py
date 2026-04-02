from typing import List


class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        max_sum = 0
        min_sum = 0
        curr_max = 0
        curr_min = 0
        for num in nums:
            curr_max = max(curr_max + num, num)
            curr_min = min(curr_min + num, num)
            max_sum = max(max_sum, curr_max)
            min_sum = min(min_sum, curr_min)
        return max(max_sum, -min_sum)
