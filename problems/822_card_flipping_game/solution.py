from typing import List


class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        same = {fronts[i] for i in range(len(fronts)) if fronts[i] == backs[i]}
        res = float('inf')
        for x in fronts + backs:
            if x not in same:
                res = min(res, x)
        return res if res != float('inf') else 0
