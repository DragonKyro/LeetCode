from typing import List


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        max_seen = float('-inf')
        min_seen = float('inf')
        end = -1
        start = 0
        for i in range(n):
            max_seen = max(max_seen, nums[i])
            if nums[i] < max_seen:
                end = i
        for i in range(n - 1, -1, -1):
            min_seen = min(min_seen, nums[i])
            if nums[i] > min_seen:
                start = i
        return end - start + 1 if end != -1 else 0
