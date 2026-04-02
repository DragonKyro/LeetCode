class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        dp = list(range(n))
        for center in range(n):
            for left, right in [(center, center), (center, center + 1)]:
                while left >= 0 and right < n and s[left] == s[right]:
                    dp[right] = min(dp[right], dp[left - 1] + 1 if left > 0 else 0)
                    left -= 1
                    right += 1
        return dp[-1]
