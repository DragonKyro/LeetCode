from typing import List


class Solution:
    def maxPointsInsideSquare(self, points: List[List[int]], s: str) -> int:
        from collections import defaultdict
        tag_dists = defaultdict(list)
        for i, (x, y) in enumerate(points):
            d = max(abs(x), abs(y))
            tag_dists[s[i]].append(d)
        limit = float('inf')
        for tag, dists in tag_dists.items():
            dists.sort()
            if len(dists) >= 2:
                limit = min(limit, dists[1])
        res = 0
        for tag, dists in tag_dists.items():
            if dists[0] < limit:
                res += 1
        return res
