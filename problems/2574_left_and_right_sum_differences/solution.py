from typing import List


class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        total = sum(nums)
        left = 0
        ans = []
        for i in range(n):
            right = total - left - nums[i]
            ans.append(abs(left - right))
            left += nums[i]
        return ans
