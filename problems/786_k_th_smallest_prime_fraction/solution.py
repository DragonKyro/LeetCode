from typing import List


class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        lo, hi = 0.0, 1.0
        n = len(arr)
        while lo < hi:
            mid = (lo + hi) / 2
            count = 0
            best = (0, 1)
            j = 1
            for i in range(n):
                while j < n and arr[i] / arr[j] > mid:
                    j += 1
                count += n - j
                if j < n and arr[i] * best[1] > best[0] * arr[j]:
                    best = (arr[i], arr[j])
            if count == k:
                return [best[0], best[1]]
            elif count < k:
                lo = mid
            else:
                hi = mid
        return []
