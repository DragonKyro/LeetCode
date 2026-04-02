from typing import List


class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        def isIncreasing(arr: List[int]) -> bool:
            for i in range(1, len(arr)):
                if arr[i] <= arr[i - 1]:
                    return False
            return True
        for i in range(len(nums)):
            if i > 0 and i < len(nums) - 1 and nums[i - 1] >= nums[i + 1]:
                continue
            if isIncreasing(nums[:i] + nums[i + 1:]):
                return True
        return False
