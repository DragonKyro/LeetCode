from typing import List


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total = 0
        max_sum = cur_max = float('-inf')
        min_sum = cur_min = float('inf')
        for num in nums:
            total += num
            cur_max = max(cur_max + num, num)
            max_sum = max(max_sum, cur_max)
            cur_min = min(cur_min + num, num)
            min_sum = min(min_sum, cur_min)
        if max_sum < 0:
            return max_sum
        return max(max_sum, total - min_sum)
