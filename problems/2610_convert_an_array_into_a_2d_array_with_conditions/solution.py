from typing import List


class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        from collections import Counter
        cnt = Counter(nums)
        res = []
        while cnt:
            row = list(cnt.keys())
            res.append(row)
            for k in row:
                cnt[k] -= 1
                if cnt[k] == 0:
                    del cnt[k]
        return res
