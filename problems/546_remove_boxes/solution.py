from typing import List


class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        from functools import lru_cache
        
        @lru_cache(maxsize=None)
        def dp(l: int, r: int, k: int) -> int:
            if l > r:
                return 0
            while r > l and boxes[r] == boxes[r - 1]:
                r -= 1
                k += 1
            res = (k + 1) * (k + 1) + dp(l, r - 1, 0)
            for i in range(l, r):
                if boxes[i] == boxes[r]:
                    res = max(res, dp(l, i, k + 1) + dp(i + 1, r - 1, 0))
            return res
        
        return dp(0, len(boxes) - 1, 0)
