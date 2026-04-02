class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 10**9 + 7
        dp = [0] * (k + 1)
        dp[0] = 1
        for i in range(2, n + 1):
            new_dp = [0] * (k + 1)
            prefix = [0] * (k + 2)
            for j in range(k + 1):
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD
            for j in range(k + 1):
                new_dp[j] = (prefix[j + 1] - prefix[max(0, j - i + 1)]) % MOD
            dp = new_dp
        return dp[k] % MOD
