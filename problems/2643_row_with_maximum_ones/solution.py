from typing import List


class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        best = [0, 0]
        for i, row in enumerate(mat):
            cnt = sum(row)
            if cnt > best[1]:
                best = [i, cnt]
        return best
