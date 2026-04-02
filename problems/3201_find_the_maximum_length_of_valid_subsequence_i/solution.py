from typing import List


class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        n = len(nums)
        even = sum(1 for x in nums if x % 2 == 0)
        odd = n - even
        alt = 0
        last = -1
        for x in nums:
            if last == -1 or x % 2 != last:
                alt += 1
                last = x % 2
        return max(even, odd, alt)
