from typing import List


class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        n = len(prizePositions)
        dp = [0] * (n + 1)
        ans = 0
        j = 0
        for i in range(n):
            while prizePositions[i] - prizePositions[j] > k:
                j += 1
            dp[i + 1] = max(dp[i], i - j + 1)
            ans = max(ans, i - j + 1 + dp[j])
        return ans
