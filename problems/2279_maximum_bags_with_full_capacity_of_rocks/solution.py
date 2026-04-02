from typing import List


class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        remaining = sorted(c - r for c, r in zip(capacity, rocks))
        count = 0
        for r in remaining:
            if additionalRocks >= r:
                additionalRocks -= r
                count += 1
            else:
                break
        return count
