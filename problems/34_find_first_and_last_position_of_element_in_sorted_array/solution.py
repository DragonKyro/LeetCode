from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def bisect_left(nums, target):
            lo, hi = 0, len(nums)
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid
            return lo
        left = bisect_left(nums, target)
        if left >= len(nums) or nums[left] != target:
            return [-1, -1]
        right = bisect_left(nums, target + 1) - 1
        return [left, right]
