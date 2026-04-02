from typing import List


class Solution:
    def findLHS(self, nums: List[int]) -> int:
        from collections import Counter
        count = Counter(nums)
        res = 0
        for key in count:
            if key + 1 in count:
                res = max(res, count[key] + count[key + 1])
        return res
