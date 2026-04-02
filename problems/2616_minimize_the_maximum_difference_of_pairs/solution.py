from typing import List


class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        lo, hi = 0, nums[-1] - nums[0]
        while lo < hi:
            mid = (lo + hi) // 2
            count = 0
            i = 1
            while i < len(nums):
                if nums[i] - nums[i-1] <= mid:
                    count += 1
                    i += 2
                else:
                    i += 1
            if count >= p: hi = mid
            else: lo = mid + 1
        return lo
