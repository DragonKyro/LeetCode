from typing import List


class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        total = sum(nums)
        res = []
        cur = 0
        for n in nums:
            cur += n
            res.append(n)
            if cur > total - cur:
                break
        return res
