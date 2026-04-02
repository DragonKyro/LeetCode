class Solution:
    def stoneGameII(self, piles: list[int]) -> int:
        n = len(piles)
        suffix = piles[:]
        for i in range(n - 2, -1, -1):
            suffix[i] += suffix[i + 1]
        memo = {}
        def dp(i: int, m: int) -> int:
            if i >= n:
                return 0
            if 2 * m >= n - i:
                return suffix[i]
            if (i, m) in memo:
                return memo[(i, m)]
            best = 0
            for x in range(1, 2 * m + 1):
                best = max(best, suffix[i] - dp(i + x, max(m, x)))
            memo[(i, m)] = best
            return best
        return dp(0, 1)
