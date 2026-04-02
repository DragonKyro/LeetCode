from typing import List


class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        result = 0
        for bit in range(24):
            count = sum(1 for c in candidates if c & (1 << bit))
            result = max(result, count)
        return result
