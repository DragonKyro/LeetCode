class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        from collections import defaultdict
        from functools import lru_cache
        pos = defaultdict(list)
        for i, c in enumerate(ring):
            pos[c].append(i)
        n = len(ring)
        
        @lru_cache(maxsize=None)
        def dp(r: int, k: int) -> int:
            if k == len(key):
                return 0
            res = float('inf')
            for i in pos[key[k]]:
                dist = min(abs(r - i), n - abs(r - i))
                res = min(res, dist + 1 + dp(i, k + 1))
            return res
        
        return dp(0, 0)
