from typing import List


class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        lo, hi = 0, price[-1] - price[0]
        while lo < hi:
            mid = (lo + hi + 1) // 2
            cnt, prev = 1, price[0]
            for p in price[1:]:
                if p - prev >= mid:
                    cnt += 1
                    prev = p
            if cnt >= k: lo = mid
            else: hi = mid - 1
        return lo
