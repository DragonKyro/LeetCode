from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        res = 0
        curr = {}
        for x in nums:
            nxt = {}
            for v, c in curr.items():
                nv = v & x
                nxt[nv] = nxt.get(nv, 0) + c
            nxt[x] = nxt.get(x, 0) + 1
            res += nxt.get(k, 0)
            curr = nxt
        return res
