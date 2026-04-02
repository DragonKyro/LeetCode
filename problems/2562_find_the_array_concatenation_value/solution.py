from typing import List


class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        val = 0
        i, j = 0, len(nums) - 1
        while i < j:
            val += int(str(nums[i]) + str(nums[j]))
            i += 1
            j -= 1
        if i == j:
            val += nums[i]
        return val
