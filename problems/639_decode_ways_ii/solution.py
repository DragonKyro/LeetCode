class Solution:
    def numDecodings(self, s: str) -> int:
        MOD = 10**9 + 7
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 9 if s[0] == '*' else (0 if s[0] == '0' else 1)
        for i in range(2, n + 1):
            c, p = s[i - 1], s[i - 2]
            if c == '*':
                dp[i] = 9 * dp[i - 1] % MOD
            elif c != '0':
                dp[i] = dp[i - 1]
            if p == '*':
                if c == '*':
                    dp[i] = (dp[i] + 15 * dp[i - 2]) % MOD
                elif c <= '6':
                    dp[i] = (dp[i] + 2 * dp[i - 2]) % MOD
                else:
                    dp[i] = (dp[i] + dp[i - 2]) % MOD
            elif p == '1':
                if c == '*':
                    dp[i] = (dp[i] + 9 * dp[i - 2]) % MOD
                else:
                    dp[i] = (dp[i] + dp[i - 2]) % MOD
            elif p == '2':
                if c == '*':
                    dp[i] = (dp[i] + 6 * dp[i - 2]) % MOD
                elif c <= '6':
                    dp[i] = (dp[i] + dp[i - 2]) % MOD
        return dp[n] % MOD
