from typing import List


class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        def canPlace(dist: int) -> bool:
            count = 1
            last = position[0]
            for i in range(1, len(position)):
                if position[i] - last >= dist:
                    count += 1
                    last = position[i]
                    if count >= m:
                        return True
            return False
        lo, hi = 1, position[-1] - position[0]
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if canPlace(mid):
                lo = mid
            else:
                hi = mid - 1
        return lo
