from typing import List


class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        from collections import defaultdict
        dp_val = [defaultdict(int) for _ in range(k + 1)]
        best = [0] * (k + 1)
        res = 0
        for x in nums:
            for j in range(k, -1, -1):
                cur = dp_val[j][x] + 1
                if j > 0:
                    cur = max(cur, best[j - 1] + 1)
                dp_val[j][x] = max(dp_val[j][x], cur)
                best[j] = max(best[j], cur)
                res = max(res, cur)
        return res
