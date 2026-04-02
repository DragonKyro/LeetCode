from typing import List


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        from math import gcd
        n = len(points)
        if n <= 2:
            return n
        result = 2
        for i in range(n):
            slopes = {}
            for j in range(i + 1, n):
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]
                g = gcd(abs(dx), abs(dy))
                if g != 0:
                    dx //= g
                    dy //= g
                if dx < 0 or (dx == 0 and dy < 0):
                    dx, dy = -dx, -dy
                slopes[(dx, dy)] = slopes.get((dx, dy), 0) + 1
            if slopes:
                result = max(result, max(slopes.values()) + 1)
        return result
