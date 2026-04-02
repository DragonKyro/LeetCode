from typing import List


class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        cost = list(range(1, 27))
        for i, c in enumerate(chars):
            cost[ord(c) - ord('a')] = vals[i]
        ans = 0
        cur = 0
        for c in s:
            cur += cost[ord(c) - ord('a')]
            if cur < 0: cur = 0
            ans = max(ans, cur)
        return ans
