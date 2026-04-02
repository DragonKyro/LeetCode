from typing import List


class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        ans = -1
        n = len(nums)
        for i in range(n - 1):
            if nums[i + 1] - nums[i] == 1:
                j = i + 1
                expected = -1
                while j + 1 < n and nums[j + 1] - nums[j] == expected:
                    j += 1
                    expected *= -1
                ans = max(ans, j - i + 1)
        return ans
