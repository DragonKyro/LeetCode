class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        import math
        a = 0
        while a * a <= c:
            b = math.isqrt(c - a * a)
            if b * b == c - a * a:
                return True
            a += 1
        return False
