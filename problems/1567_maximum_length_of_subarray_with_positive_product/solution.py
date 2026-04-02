from typing import List


class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        pos = neg = 0
        res = 0
        for n in nums:
            if n > 0:
                pos += 1
                neg = neg + 1 if neg > 0 else 0
            elif n < 0:
                new_pos = neg + 1 if neg > 0 else 0
                neg = pos + 1
                pos = new_pos
            else:
                pos = neg = 0
            res = max(res, pos)
        return res
