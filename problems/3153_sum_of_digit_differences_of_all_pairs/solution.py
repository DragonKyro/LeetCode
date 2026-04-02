from typing import List


class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        n = len(nums)
        s = [str(x) for x in nums]
        d = len(s[0])
        res = 0
        for pos in range(d):
            cnt = [0] * 10
            for i in range(n):
                cnt[int(s[i][pos])] += 1
            for c in cnt:
                res += c * (n - c)
        return res // 2
