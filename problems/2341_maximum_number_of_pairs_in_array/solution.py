from typing import List


class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        count = Counter(nums)
        pairs = sum(v // 2 for v in count.values())
        leftover = len(nums) - pairs * 2
        return [pairs, leftover]
