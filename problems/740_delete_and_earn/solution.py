from typing import List


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_val = max(nums)
        points = [0] * (max_val + 1)
        for num in nums:
            points[num] += num
        take, skip = 0, 0
        for i in range(1, max_val + 1):
            take, skip = skip + points[i], max(take, skip)
        return max(take, skip)
