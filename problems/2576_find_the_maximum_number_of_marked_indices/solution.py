from typing import List


class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        j = n // 2
        i = 0
        while i < n // 2 and j < n:
            if 2 * nums[i] <= nums[j]:
                ans += 2
                i += 1
            j += 1
        return ans
