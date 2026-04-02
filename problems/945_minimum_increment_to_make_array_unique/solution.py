from typing import List


class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        result = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                result += nums[i - 1] + 1 - nums[i]
                nums[i] = nums[i - 1] + 1
        return result
