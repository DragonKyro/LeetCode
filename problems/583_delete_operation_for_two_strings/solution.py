class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            new_dp = [0] * (n + 1)
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    new_dp[j] = dp[j - 1] + 1
                else:
                    new_dp[j] = max(dp[j], new_dp[j - 1])
            dp = new_dp
        lcs = dp[n]
        return m + n - 2 * lcs
