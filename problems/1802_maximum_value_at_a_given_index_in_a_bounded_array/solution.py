class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def count(mid: int) -> int:
            left_count = min(mid - 1, index)
            right_count = min(mid - 1, n - 1 - index)
            total = mid
            if left_count < index:
                total += left_count * (left_count + 1) // 2 + (index - left_count)
            else:
                total += left_count * (left_count + 1) // 2 - (left_count - index) * (left_count - index + 1) // 2
            if right_count < n - 1 - index:
                total += right_count * (right_count + 1) // 2 + (n - 1 - index - right_count)
            else:
                total += right_count * (right_count + 1) // 2 - (right_count - (n - 1 - index)) * (right_count - (n - 1 - index) + 1) // 2
            return total
        lo, hi = 1, maxSum
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if count(mid) <= maxSum:
                lo = mid
            else:
                hi = mid - 1
        return lo
