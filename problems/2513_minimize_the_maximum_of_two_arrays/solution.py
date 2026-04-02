class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
        from math import gcd
        lcm = divisor1 * divisor2 // gcd(divisor1, divisor2)
        lo, hi = 1, 2 * 10**9
        while lo < hi:
            mid = (lo + hi) // 2
            a = mid - mid // divisor1
            b = mid - mid // divisor2
            c = mid - mid // lcm
            if a >= uniqueCnt1 and b >= uniqueCnt2 and c >= uniqueCnt1 + uniqueCnt2:
                hi = mid
            else:
                lo = mid + 1
        return lo
