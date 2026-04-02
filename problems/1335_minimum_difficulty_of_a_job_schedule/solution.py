class Solution:
    def minDifficulty(self, jobDifficulty: list[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        dp = [[float('inf')] * n for _ in range(d)]
        dp[0][0] = jobDifficulty[0]
        for j in range(1, n):
            dp[0][j] = max(dp[0][j - 1], jobDifficulty[j])
        for i in range(1, d):
            for j in range(i, n):
                max_d = 0
                for k in range(j, i - 1, -1):
                    max_d = max(max_d, jobDifficulty[k])
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + max_d)
        return dp[d - 1][n - 1]
