from typing import List


class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        result = []
        for xc, yc, r in queries:
            count = 0
            for xp, yp in points:
                if (xp - xc) ** 2 + (yp - yc) ** 2 <= r ** 2:
                    count += 1
            result.append(count)
        return result
