class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        from math import gcd
        def lcm(x: int, y: int) -> int:
            return x * y // gcd(x, y)
        ab = lcm(a, b)
        ac = lcm(a, c)
        bc = lcm(b, c)
        abc = lcm(ab, c)
        def count(num: int) -> int:
            return num // a + num // b + num // c - num // ab - num // ac - num // bc + num // abc
        lo, hi = 1, 2 * 10 ** 9
        while lo < hi:
            mid = (lo + hi) // 2
            if count(mid) < n:
                lo = mid + 1
            else:
                hi = mid
        return lo
