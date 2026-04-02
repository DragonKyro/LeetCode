from typing import List


class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        MOD = 10**9 + 7
        ranges.sort()
        groups = 0
        end = -1
        for s, e in ranges:
            if s > end:
                groups += 1
            end = max(end, e)
        return pow(2, groups, MOD)
