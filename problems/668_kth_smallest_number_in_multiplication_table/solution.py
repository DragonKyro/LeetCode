class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        lo, hi = 1, m * n
        while lo < hi:
            mid = (lo + hi) // 2
            count = 0
            for i in range(1, m + 1):
                count += min(mid // i, n)
            if count < k:
                lo = mid + 1
            else:
                hi = mid
        return lo
