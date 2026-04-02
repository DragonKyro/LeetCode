from typing import List


class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        max_idx = nums.index(max(nums))
        for i, num in enumerate(nums):
            if i != max_idx and nums[max_idx] < 2 * num:
                return -1
        return max_idx
