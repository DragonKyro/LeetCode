from typing import List


class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        from collections import Counter
        cnt = Counter(power)
        vals = sorted(cnt.keys())
        n = len(vals)
        dp = [0] * (n + 1)
        j = 0
        for i in range(n):
            dp[i + 1] = dp[i]
            while j < i and vals[j] < vals[i] - 2:
                j += 1
            take = dp[j] + vals[i] * cnt[vals[i]]
            dp[i + 1] = max(dp[i + 1], take)
        return dp[n]
