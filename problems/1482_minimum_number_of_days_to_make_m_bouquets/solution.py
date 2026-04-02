from typing import List


class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1
        def canMake(days: int) -> bool:
            bouquets = 0
            flowers = 0
            for b in bloomDay:
                if b <= days:
                    flowers += 1
                    if flowers == k:
                        bouquets += 1
                        flowers = 0
                else:
                    flowers = 0
            return bouquets >= m
        lo, hi = min(bloomDay), max(bloomDay)
        while lo < hi:
            mid = (lo + hi) // 2
            if canMake(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
