from typing import List


class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        total = sum(nums)
        prefix = 0
        result = []
        for i in range(n):
            left_sum = prefix
            right_sum = total - prefix - nums[i]
            result.append(nums[i] * i - left_sum + right_sum - nums[i] * (n - i - 1))
            prefix += nums[i]
        return result
