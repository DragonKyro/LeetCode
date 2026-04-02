from typing import List


class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        lo, hi = min(nums), max(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            count = 0
            i = 0
            while i < len(nums):
                if nums[i] <= mid:
                    count += 1
                    i += 2
                else:
                    i += 1
            if count >= k: hi = mid
            else: lo = mid + 1
        return lo
