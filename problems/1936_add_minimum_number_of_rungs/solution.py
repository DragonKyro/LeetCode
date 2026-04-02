from typing import List


class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        result = 0
        prev = 0
        for r in rungs:
            result += (r - prev - 1) // dist
            prev = r
        return result
