from typing import List


class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        total = 0
        n = len(nums)
        for bit in range(32):
            ones = sum(1 for num in nums if num & (1 << bit))
            total += ones * (n - ones)
        return total
