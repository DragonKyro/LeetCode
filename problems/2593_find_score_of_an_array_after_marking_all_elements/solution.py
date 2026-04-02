from typing import List


class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        idx = sorted(range(n), key=lambda i: (nums[i], i))
        marked = [False] * n
        score = 0
        for i in idx:
            if not marked[i]:
                score += nums[i]
                marked[i] = True
                if i > 0: marked[i-1] = True
                if i < n-1: marked[i+1] = True
        return score
