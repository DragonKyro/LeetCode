from typing import List


class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        from collections import defaultdict
        cnt = defaultdict(lambda: defaultdict(int))
        for p, c in pick:
            cnt[p][c] += 1
        res = 0
        for p in range(n):
            if any(v > p for v in cnt[p].values()):
                res += 1
        return res
