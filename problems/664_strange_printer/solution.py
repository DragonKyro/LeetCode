class Solution:
    def strangePrinter(self, s: str) -> int:
        s = ''.join(c for i, c in enumerate(s) if i == 0 or c != s[i - 1])
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = dp[i + 1][j] + 1
                for k in range(i + 1, j + 1):
                    if s[k] == s[i]:
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + (dp[k][j] if k <= j else 0))
        return dp[0][n - 1] if n > 0 else 0
