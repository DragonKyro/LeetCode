from typing import List


class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)
        h = v = 0
        hp = vp = 1
        res = 0
        while h < len(horizontalCut) and v < len(verticalCut):
            if horizontalCut[h] >= verticalCut[v]:
                res += horizontalCut[h] * vp
                hp += 1
                h += 1
            else:
                res += verticalCut[v] * hp
                vp += 1
                v += 1
        while h < len(horizontalCut):
            res += horizontalCut[h] * vp
            h += 1
        while v < len(verticalCut):
            res += verticalCut[v] * hp
            v += 1
        return res
