from typing import List


class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 0
        j = 0
        for i in range(len(nums)):
            while nums[i] - nums[j] > 2 * k:
                j += 1
            ans = max(ans, i - j + 1)
        return ans
