class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        def count_zeros(n):
            count = 0
            d = 5
            while d <= n:
                count += n // d
                d *= 5
            return count
        def lower_bound(target):
            lo, hi = 0, 5 * (target + 1)
            while lo < hi:
                mid = (lo + hi) // 2
                if count_zeros(mid) < target:
                    lo = mid + 1
                else:
                    hi = mid
            return lo
        return lower_bound(k + 1) - lower_bound(k)
