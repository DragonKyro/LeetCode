from typing import List


class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        xs = sorted(set(p[0] for p in points))
        res = 0
        i = 0
        while i < len(xs):
            start = xs[i]
            res += 1
            while i < len(xs) and xs[i] <= start + w:
                i += 1
        return res
