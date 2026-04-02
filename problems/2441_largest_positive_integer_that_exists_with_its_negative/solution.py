from typing import List


class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set(nums)
        result = -1
        for n in nums:
            if n > 0 and -n in s:
                result = max(result, n)
        return result
