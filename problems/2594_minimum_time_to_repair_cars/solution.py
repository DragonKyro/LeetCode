from typing import List


class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        lo, hi = 1, min(ranks) * cars * cars
        while lo < hi:
            mid = (lo + hi) // 2
            total = sum(int((mid // r) ** 0.5) for r in ranks)
            if total >= cars: hi = mid
            else: lo = mid + 1
        return lo
