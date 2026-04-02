from typing import List


class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        res = float('inf')
        curr = set()
        for x in nums:
            nxt = set()
            nxt.add(x)
            for v in curr:
                nxt.add(v & x)
            for v in nxt:
                res = min(res, abs(v - k))
            curr = nxt
        return res
