from typing import List


class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans = 0
        n = len(nums)
        i = 0
        while i < n:
            if nums[i] % 2 == 0 and nums[i] <= threshold:
                j = i
                while j + 1 < n and nums[j+1] % 2 != nums[j] % 2 and nums[j+1] <= threshold:
                    j += 1
                ans = max(ans, j - i + 1)
                i = j + 1
            else:
                i += 1
        return ans
