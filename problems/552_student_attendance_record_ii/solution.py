class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10**9 + 7
        dp = [[0] * 3 for _ in range(2)]
        dp[0][0] = 1
        for _ in range(n):
            new_dp = [[0] * 3 for _ in range(2)]
            for a in range(2):
                for l in range(3):
                    if dp[a][l] == 0:
                        continue
                    new_dp[a][0] = (new_dp[a][0] + dp[a][l]) % MOD
                    if a < 1:
                        new_dp[a + 1][0] = (new_dp[a + 1][0] + dp[a][l]) % MOD
                    if l < 2:
                        new_dp[a][l + 1] = (new_dp[a][l + 1] + dp[a][l]) % MOD
            dp = new_dp
        return sum(dp[a][l] for a in range(2) for l in range(3)) % MOD
