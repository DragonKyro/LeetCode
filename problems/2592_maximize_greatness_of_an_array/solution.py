from typing import List


class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        j = 0
        for i in range(len(nums)):
            if nums[i] > nums[j]:
                j += 1
        return j
