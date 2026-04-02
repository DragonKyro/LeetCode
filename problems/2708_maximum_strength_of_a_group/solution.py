from typing import List


class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]
        neg = sorted([x for x in nums if x < 0])
        pos = [x for x in nums if x > 0]
        if len(neg) % 2 == 1:
            neg = neg[:-1]
        if not neg and not pos:
            return 0
        result = 1
        for x in neg + pos:
            result *= x
        return result
