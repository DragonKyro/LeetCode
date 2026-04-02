from typing import List


class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        res = []
        for s, e in intervals:
            if not res or res[-1] < s:
                res.extend([e - 1, e])
            elif res[-2] < s:
                res.append(e)
        return len(res)
