from typing import List


class Solution:
    def averageValue(self, nums: List[int]) -> int:
        vals = [n for n in nums if n % 6 == 0]
        return sum(vals) // len(vals) if vals else 0
