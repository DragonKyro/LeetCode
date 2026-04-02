from typing import List


class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        arr.sort()
        dp = {}
        for x in arr:
            dp[x] = 1
            for y in arr:
                if y * y > x:
                    break
                if x % y == 0 and x // y in dp:
                    if y == x // y:
                        dp[x] = (dp[x] + dp[y] * dp[y]) % MOD
                    else:
                        dp[x] = (dp[x] + 2 * dp[y] * dp[x // y]) % MOD
        return sum(dp.values()) % MOD
