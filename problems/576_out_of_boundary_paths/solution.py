class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 10**9 + 7
        from functools import lru_cache
        
        @lru_cache(maxsize=None)
        def dp(r: int, c: int, moves: int) -> int:
            if r < 0 or r >= m or c < 0 or c >= n:
                return 1
            if moves == 0:
                return 0
            return (dp(r-1,c,moves-1) + dp(r+1,c,moves-1) + dp(r,c-1,moves-1) + dp(r,c+1,moves-1)) % MOD
        
        return dp(startRow, startColumn, maxMove)
