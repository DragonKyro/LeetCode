from typing import List


class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        for row in nums:
            row.sort(reverse=True)
        score = 0
        for c in range(len(nums[0])):
            score += max(nums[r][c] for r in range(len(nums)))
        return score
