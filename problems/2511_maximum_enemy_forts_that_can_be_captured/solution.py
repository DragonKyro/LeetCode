from typing import List


class Solution:
    def captureForts(self, forts: List[int]) -> int:
        ans, prev = 0, -1
        for i, f in enumerate(forts):
            if f != 0:
                if prev >= 0 and forts[prev] != f:
                    ans = max(ans, i - prev - 1)
                prev = i
        return ans
