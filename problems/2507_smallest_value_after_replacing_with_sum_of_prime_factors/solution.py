class Solution:
    def smallestValue(self, n: int) -> int:
        while True:
            s, x = 0, n
            d = 2
            while d * d <= x:
                while x % d == 0:
                    s += d
                    x //= d
                d += 1
            if x > 1:
                s += x
            if s == n:
                return n
            n = s
