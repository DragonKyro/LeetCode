from typing import List


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        from collections import Counter
        count = Counter(nums)
        return sum(v * (v - 1) // 2 for v in count.values())
